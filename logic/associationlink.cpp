#include "associationlink.h"

using namespace Logic;

Link::Link(Entity *entity, Cardinality max,Cardinality min)
    : m_max(max)
    , m_min(min)
    , m_entity(entity)
{
}
Link::~Link()
{
}

Link::Cardinality Link::max()
{
    return m_max;
}

Link::Cardinality Link::min()
{
    return m_min;
}

void Link::setMax(Link::Cardinality Cardinality)
{
    m_max = Cardinality;
}

void Link::setMin(Link::Cardinality Value)
{
    m_min = Value;
}

Entity* Link::entity()
{
    return m_entity;
}

void Link::setEntity(Entity *entity)
{
    m_entity = entity;
}

