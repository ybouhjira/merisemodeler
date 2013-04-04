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
        I->toXml() = root.append_child(I->name().toStdString().c_str());
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
        items.append(E->fromXml(entity));
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
                        }
                    }
                }
            }
        }
    }


    for (int i = 0; i < entities.length(); ++i) {
        for (int j = 0; j < entities.length(); ++j) {
            if(parentsList.at(i) == items.at(j)->name())
            {
                E->addParent((Logic::Entity*)items.at(j));
            }
        }
    }

    //Reading the associations
    QList<Logic::Association*> associations;
    foreach (pugi::xml_node assoc, doc.children("association")) {
        Association *A;
        associations.append(A->fromXml(assoc));
    }

    return items;
}

