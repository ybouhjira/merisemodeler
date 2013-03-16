#include "item.h"
#include "property.h"

using namespace Logic;

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
    emit propertiesEdited();
}

void Item::removeProperty(int index)
{
    m_properties.removeAt(index);
}

void Item::removeProperty(Property *property)
{
    m_properties.removeOne(property);
}

QList<Logic::Property*> Item::properties() {
    return m_properties;
}
