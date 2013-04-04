#include <QFile>
#include "mcdmodel.h"
#include "logic/entity.h"
#include "logic/association.h"
#include "logic/associationlink.h"
#include "model/mcdscene.h"

// Qt
#include <QRegularExpression>
#include <QRegularExpressionMatch>

using namespace Logic;
using namespace Model;

McdModel::McdModel(QObject *parent)
    : QObject(parent)
    , m_scene(new Model::McdScene(this))
{
}

McdModel::~McdModel() {
}

QList<Item*> McdModel::items() const {
    return m_items;
}

void McdModel::addItem(Item *item) {
    item->setParent(this);
    m_items.append(item);
}

void McdModel::removeItem(int index) {
    delete m_items[index];
    m_items.removeAt(index);
    emit itemRemoved(index);
}

void McdModel::removeItem(Item *item) {
    for (int i = 0; i < m_items.size(); ++i) {
        if( item == m_items[i]) {
            delete m_items[i];
            m_items.removeAt(i);
            emit itemRemoved(i);
            return;
        }
    }
}

McdScene* McdModel::scene() const {
    return m_scene;
}

Entity* McdModel::createEntity() {
    QString entityName = tr("Entity");
    QString nameSuffix = "" ;

    QListIterator<Item*> iterator(m_items);
    while(iterator.hasNext()) {
        while(iterator.hasNext()) {
            if(iterator.next()->name()  == entityName + nameSuffix) {
                nameSuffix = QString::number(nameSuffix.toInt() + 1);
                iterator.toFront();
                break;
            }
        }
    }

    // Ajout de l'entité au Model
    auto entity = new Entity(entityName + nameSuffix) ;
    m_items.append(entity);
    return entity;
}

Association* McdModel::createAssociation(Entity *first, Entity *second) {
    QString assocName = tr("Association");
    QString nameSuffix = "";

    QListIterator<Item*> iterator(m_items);
    while(iterator.hasNext()) {
        while(iterator.hasNext()) {
            if(iterator.next()->name()  == assocName + nameSuffix) {
                nameSuffix = QString::number(nameSuffix.toInt() + 1);
                iterator.toFront();
                break;
            }
        }
    }

    QString name = assocName + nameSuffix ;
    Association *association = new Association(name, first, second);
    addItem(association);
    return association;
}
void McdModel::saveXml(QString filename)
{
    pugi::xml_document doc;
    pugi::xml_node root = doc.append_child("model");
    foreach (Item *I, items()) {
        I->toXml() = root.append_child("");
    }
    doc.save_file(filename.toStdString().c_str());
}
QList<Logic::Item*> McdModel::fromXml(QString fileName)
{
    pugi::xml_document doc;
    doc.load_file(fileName.toStdString().c_str());

    QList<Logic::Item*> items;

    //Reading the entities
    QList<Logic::Entity*> entities;
    foreach (pugi::xml_node entity , doc.children("entity")) {
        Entity *E;
        entities.append(E->fromXml(entity));
    }

    //fixing parents
    foreach (pugi::xml_node en, doc.children("entity")) {
        pugi::xml_node parents = en.child("parents");
        //Parents names
        QList<QString> parentsList;
        foreach (pugi::xml_node parent, parents.children()) {
            parentsList.append(parent.attribute("name").value());
        }
        //appending the parents
        for (int i = 0; i < entities.length(); ++i) {
            if(entities.at(i)->name().toStdString().c_str() == en.attribute("name").value())
            {
                for (int j = 0; j < parentsList.length(); ++j) {
                    for (int k = 0; k < entities.length(); ++k) {
                        if(parentsList.at(j) == entities.at(k)->name())
                        {
                            entities.at(i)->addParent(entities.at(k));
                            items.append(entities.at(i));
                        }
                    }
                }
            }
        }
    }


    //Reading the associations
    foreach (pugi::xml_node assoc, doc.children("association")) {
        QString Aname = assoc.attribute("name").value();

        pugi::xml_node assocProperties = assoc.child("properties");
        QList<Logic::Property*> propertiesList;
        foreach (pugi::xml_node Xproperty, assocProperties.children("property")) {
            //Property attributes
            QString name = Xproperty.attribute("name").value();
            QString type = Xproperty.attribute("type").value();
            QString check = Xproperty.attribute("check").value();
            QString defaultValue = Xproperty.attribute("default-value").value();
            QString identifier = Xproperty.attribute("identifier").value();
            QString obligatory = Xproperty.attribute("obligtory").value();
            bool id = (identifier == "true")?true:false;
            bool ob = (obligatory == "true")?true:false;
            Type T(type);
            //Appending property to the Property list
            propertiesList.append(new Property(name,T,ob,check,defaultValue,id));
        }

        Logic::Link *L1;
        pugi::xml_node En1 = assoc.child("entity1");
        QString En1_name = En1.attribute("name").value();
        //The entity
        for (int i = 0; i < entities.length(); ++i) {
            if(En1_name == entities.at(i)->name())
            {
                L1->setEntity((Entity*)entities.at(i));
            }
        }

        //The cardinalities
        QString max1 = En1.attribute("max").value();
        QString min1 = En1.attribute("min").value();
        L1->setMax(Logic::Link::stringToCardinality(max1));
        L1->setMin(Logic::Link::stringToCardinality(min1));

        //The second Entity
        Logic::Link *L2;
        pugi::xml_node En2 = assoc.child("entity2");
        QString En2_name = En2.attribute("name").value();
        //The entity
        for (int i = 0; i < entities.length(); ++i) {
            if (En2_name == entities.at(i)->name()) {
                L2->setEntity((Entity*)entities.at(i));
            }
        }
        //The Cardinalities
        QString max2 = En2.attribute("max").value();
        QString min2 = En2.attribute("min").value();
        L2->setMax(Logic::Link::stringToCardinality(max2));
        L2->setMin(Logic::Link::stringToCardinality(min2));


        //Entities Pair
        QPair<Link*,Link*> entitiesLinks;
        entitiesLinks.first = L1;
        entitiesLinks.second = L2;

        Association *association = new Association(Aname,entitiesLinks);
        association->setProperties(propertiesList);

        items.append(association);
    }

    return items;
}

