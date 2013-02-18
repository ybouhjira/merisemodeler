#include "entity.h"

Entity::Entity(QString const &name
               , QList<Entity*> parents = QList<Entity*>()
               , auto uniqueConstraints = QList<UniqueConstraint*>()
               , Identifier * identifier)
    : Item(name)
    , m_parents(new QList<Entity*>(parents))
    , m_uniqueConstraints(new QList<UniqueConstraint*>(uniqueConstraints))
    , m_identifier(new Identifier(identifier))
{
}
Entity::~Item()
{
}
void Entity::addParent(Entity *parent)
{
    m_parents.append(parent);
}
void Entity::addProperty(Property *property)
{
    m_properties.append(property);
}
void Entity::addUniqueConstraint(UniqueConstraint *uniqueConstraint)
{
    m_uniqueConstraints.append(uniqueConstraint);
}
void Entity::setIdentifier(Identifier *identifier)
{
    m_identifier = identifier;
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
QList<Property*> Entity::properties()
{
    return m_properties;
}
Identifier* Entity::identifier()
{
    return m_identifier;
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
void Entity::removeProperty(int index)
{
    m_properties.removeAt(index);
}
void Entity::removeProperty(Property *property)
{
    m_properties.removeOne(property);
}
void Entity::removeUniqueConstraint(int index)
{
    m_uniqueConstraints.removeOne(index);
}
void Entity::removeUniqueConstraint(UniqueConstraint *uniqueConstraint)
{
    m_uniqueConstraints.removeOne(uniqueConstraint);
}


