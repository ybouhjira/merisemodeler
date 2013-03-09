#include "associationlink.h"

AssociationLink::AssociationLink(Entity *entity, Cardinality max,Cardinality min)
    : m_max(max)
    , m_min(min)
    , m_entity(entity)
{
}
AssociationLink::~AssociationLink()
{
}

AssociationLink::Cardinality AssociationLink::max()
{
    return m_max;
}

AssociationLink::Cardinality AssociationLink::min()
{
    return m_min;
}

void AssociationLink::setMax(AssociationLink::Cardinality Cardinality)
{
    m_max = Cardinality;
}

void AssociationLink::setMin(AssociationLink::Cardinality Value)
{
    m_min = Value;
}

Entity* AssociationLink::entity()
{
    return m_entity;
}

void AssociationLink::setEntity(Entity *entity)
{
    m_entity = entity;
}

