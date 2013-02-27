#include "entity.h"

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
{}
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


