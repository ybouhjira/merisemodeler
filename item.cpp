#include "item.h"

Item::Item(QString const & name)
    : m_name(name)
{
}

Item::~Item()
{
    for(int i=0;i<m_properties.length();i++)
        delete m_properties.at(i);
}

QString Item::name() const
{
    return m_name;
}

void Item::setName(QString const &name)
{
    m_name = name;
}

void Item::addProperty(Property *property)
{
    m_properties.append(property);
}

void Item::removeProperty(int index)
{
    m_properties.removeAt(index);
}

void Item::removeProperty(Property *property)
{
    m_properties.removeOne(property);
}

QList<Property*> Item::properties() {
    return m_properties;
}
