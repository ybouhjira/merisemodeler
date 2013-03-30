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
    writeProperties() = entity_node.append_child("Properties");

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

