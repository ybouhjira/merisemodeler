#include "multipropertyconstraint.h"

MultiPropertyConstraint::MultiPropertyConstraint(QList<Property *> properties)

{
    for(int i= 0 ;i<properties.length();i++)
    {
        m_properties.append(properties.at(i));
    }
}
MultiPropertyConstraint::~MultiPropertyConstraint()
{

}
QList<Property*> MultiPropertyConstraint::properties()
{
    return m_properties;
}
void MultiPropertyConstraint::addProperty(Property *property)
{
    m_properties.append(property);
}
void MultiPropertyConstraint::removeProperty(int index)
{
    m_properties.removeAt(index);
}
void MultiPropertyConstraint::removeProperty(Property *property)
{
    m_properties.removeOne(property);
}

