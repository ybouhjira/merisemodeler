#include "association.h"

Association::Association(const QString &name
                         , Cardinality *cardinality
                         , Entity *entity1
                         , Entity *entity2)
    : Item(name)
    , m_cardinality(cardinality)
    , m_entity1(entity1)
    , m_entity2(entity2)
{
}

Association::~Association()
{}

Entity* Association::entity1()
{
    return m_entity1;
}
Entity* Association::entity2()
{
    return m_entity2;
}
void Association::setEntity1(Entity *entity)
{
    m_entity1 = entity;
}
void Association::setEntity2(Entity *entity)
{
    m_entity2 = entity;
}
Cardinality* Association::cardinality()
{
    return m_cardinality;
}
void Association::setCardinality(Cardinality *cardinality)
{
    m_cardinality = cardinality;
}

