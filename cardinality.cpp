#include "cardinality.h"

Cardinality::Cardinality(value max,value min)
    : m_max(max)
    , m_min(min)
{
}
Cardinality::~Cardinality()
{

}
value Cardinality::max()
{
    return max;
}
value Cardinality::min()
{
    return min;
}
void Cardinality::setMax(value Value)
{
    m_max = Value;
}
void Cardinality::setMin(value Value)
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

