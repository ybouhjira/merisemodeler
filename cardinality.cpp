#include "cardinality.h"

Cardinality::Cardinality(Value max,Value min)
    : m_max(max)
    , m_min(min)
{
}
Cardinality::~Cardinality()
{
}

Cardinality::Value Cardinality::max()
{
    return m_max;
}

Cardinality::Value Cardinality::min()
{
    return m_min;
}

void Cardinality::setMax(Cardinality::Value Value)
{
    m_max = Value;
}

void Cardinality::setMin(Cardinality::Value Value)
{
    m_min = Value;
}

Entity* Cardinality::entity()
{
    return m_entity;
}

void Cardinality::setEntity(Entity *entity)
{
    m_entity = entity;
}

