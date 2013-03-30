#include "entity.h"

using namespace Logic;

Entity::Entity(QString const &name
               , QList<Entity*> parents
               , QList<UniqueConstraint *> uniqueConstraints
               )
    : Item(name)
    , m_parents(parents)
    , m_uniqueConstraints(uniqueConstraints)
{
}

Entity::~Entity()
{
}

void Entity::addParent(Entity *parent)
{
    m_parents.append(parent);
}

void Entity::addUniqueConstraint(UniqueConstraint *uniqueConstraint)
{
    m_uniqueConstraints.append(uniqueConstraint);
}

//ACCESSORS
QList<Entity*> Entity::parents()
{
    return m_parents;
}

QList<UniqueConstraint*> Entity::uniqueConstraints()
{
    return m_uniqueConstraints;
}

//REMOVERS
void Entity::removeParent(Entity *parent)
{
    m_parents.removeOne(parent);
}

void Entity::removeParent(int index)
{
    m_parents.removeAt(index);
}

void Entity::removeUniqueConstraint(int index)
{
    m_uniqueConstraints.removeAt(index);
}

void Entity::removeUniqueConstraint(UniqueConstraint *uniqueConstraint)
{
    m_uniqueConstraints.removeOne(uniqueConstraint);
}

Graphic::Entity* Entity::graphicObject() const {
    return m_graphicEntity ;
}

void Logic::Entity::setGraphicObject(Graphic::Entity *gEntity) {
    m_graphicEntity = gEntity;
}

//Xml Functions
pugi::xml_node Logic::Entity::toXml()
{
    pugi::xml_node entity_node;
    entity_node.set_name("entity");
    entity_node.append_attribute("name") = name().toStdString().c_str();

    //Parents node
    pugi::xml_node EntityParents = entity_node.append_child("parents");
    foreach (Entity *P, Logic::Entity::parents()) {
        pugi::xml_node EntityParent = EntityParents.append_child("parent");
        EntityParent.append_attribute("name") = P->name().toStdString().c_str();
    }

    //properties node
    writeProperties() = entity_node.append_child("properties");

    //Unique constraints node
    writeUK(uniqueConstraints()) = entity_node.append_child("UniqueConstraints");

    //Graphic properties
    pugi::xml_node graphic = entity_node.append_child("graphic");
    pugi::xml_node X = graphic.append_child("x");
    X.set_value(QString::number(graphicObject()->x()).toStdString().c_str());
    pugi::xml_node Y = graphic.append_child("y");
    Y.set_value(QString::number(graphicObject()->y()).toStdString().c_str());
    pugi::xml_node W = graphic.append_child("width");
    W.set_value(QString::number(graphicObject()->width()).toStdString().c_str());
    pugi::xml_node H = graphic.append_child("height");
    H.set_value(QString::number(graphicObject()->height()).toStdString().c_str());

    return entity_node;
}
Logic::Entity* Entity::fromXml(pugi::xml_node entity)
{
    //Reading entity name
    QString Ename = entity.attribute("name").value();

    //Reading entity's parents
    pugi::xml_node parents = entity.child("parents");
    QList<QString> parentsList;
    foreach (pugi::xml_node parent, parents.children()) {
        parentsList.append(parent.attribute("name").value());
    }

    //Reading Entity's properties
    QList<Logic::Property*> propertiesList;
    pugi::xml_node Xproperties = entity.child("properties");
    foreach (pugi::xml_node Xproperty, Xproperties.children("property")) {
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
        //Appending prperty to the Property list
        propertiesList.append(new Property(name,T,ob,check,defaultValue,id));
    }

    //Reading Entity's unique constraints
    QList<Logic::UniqueConstraint*> UKList;
    pugi::xml_node Xuks = entity.child("UniqueConstraints");
    //Every Unique Constraint
    foreach (pugi::xml_node Xuk , Xuks.children("Unique-Constraint")) {
        //UK's property list
        QList<Logic::Property*> UKProperties;
        //Every proeprty in the unique constraint
        foreach (pugi::xml_node P, Xuk.children("Unique-Constraint-Property")) {
            QString PName = P.attribute("name").value();
            for (int i = 0; i < propertiesList.size(); i++) {
                if(propertiesList.at(i)->name() == PName){
                    UKProperties.append(propertiesList.at(i));
                }
            }
        }
        UKList.append(new UniqueConstraint(UKProperties));
    }

    //The entity
    Entity *E =  new Entity(Ename,QList<Entity*>(),UKList);
    E->setProperties(propertiesList);
    return E;
}
