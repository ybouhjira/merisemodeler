#include "uniqueconstraint.h"

Logic::UniqueConstraint::UniqueConstraint(QList<Property *> properties)
{
    for(int i= 0 ;i<properties.length();i++)
    {
        m_properties.append(properties.at(i));
    }
}

Logic::UniqueConstraint::~UniqueConstraint()
{
}
 QList<Logic::Property*> Logic::UniqueConstraint::properties()
 {
     return m_properties;
 }
void Logic::UniqueConstraint::addProperty(Logic::Property *property)
{
    m_properties.append(property);
}
void Logic::UniqueConstraint::removeProperty(int index)
{
    m_properties.removeAt(index);
}
void Logic::UniqueConstraint::removeProperty(Logic::Property *property)
{
    m_properties.removeOne(property);
}
