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
QString Link::cardinalityToString(Cardinality c)
{
    switch (c) {
    case Zero:
        return "zero";
        break;
    case One:
        return "one";
        break;
    case N:
        return "n";
        break;
    default:
        break;
    }
}
Link::Cardinality Link::stringToCardinality(QString c)
{
    if(c == "zero")
        return Zero;
    if(c == "one")
        return One;
    if(c == "n")
        return N;
}
