#include "association.h"

Association::Association(const QString &name, Entity *entities)
    : Item(name)
{
    for(int i=0;i<2;i++)
        m_entities[i] = entities[i];
}
Association::~Association()
{
}

void Association::setEntity(int index, Entity *entity)
{
    m_entities[index] = entity;
}
Entity* Association::entities()
{
    return m_entities;
}
