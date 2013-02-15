#include "item.h"

Item::Item(QString const & name)
{
   m_name = name;
}

Item::~Item()
{
    for(Property* Pte : m_properties)
        delete Pte;
}

QString Item::name() const
{
    return m_name;
}

void Item::setName(const QString &name) const
{
    m_name = name;
}

void Item::addProperty(Property *property)
{
    m_properties->append(property);
}

void Item::removeProperty(int index)
{
    m_properties->removeAt(index);
}

void Item::removeProperty(Property *property)
{
    m_properties.removeOne(property);
}
