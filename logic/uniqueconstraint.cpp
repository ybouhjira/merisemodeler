#include "uniqueconstraint.h"

UniqueConstraint::UniqueConstraint(QList<Property *> properties)
{
    for(int i= 0 ;i<properties.length();i++)
    {
        m_properties.append(properties.at(i));
    }
}

UniqueConstraint::~UniqueConstraint()
{
}
 QList<Property*> UniqueConstraint::properties()
 {
     return m_properties;
 }
void UniqueConstraint::addProperty(Property *property)
{
    m_properties.append(property);
}
void UniqueConstraint::removeProperty(int index)
{
    m_properties.removeAt(index);
}
void UniqueConstraint::removeProperty(Property *property)
{
    m_properties.removeOne(property);
}
