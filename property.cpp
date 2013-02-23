#include "property.h"
Property::Property(QString const &name
                   ,Type type
                   , bool obligatory
                   , QString const &check
                   , QString const &defaultVal)
    : m_name(name)
    , m_type(type)
    , m_obligatory(obligatory)
    , m_check(check)
    , m_defaultValue(defaultVal)
{
}
Property::~Property()
{

}
QString Property::name()
{
    return m_name;
}
void Property::setName(QString const &name)
{
    m_name = name;
}
bool Property::obligatory()
{
    return m_obligatory;
}
void Property::setObligatory(bool obligatory)
{
    m_obligatory = obligatory;
}
QString Property::check()
{
    return m_check;
}
void Property::setCheck(QString const &Check)
{
    m_check = Check;
}
QString Property::defaultValue()
{
    return m_defaultValue;
}
void Property::setDefaultValue(QString const &DefaultValue)
{
    m_defaultValue = DefaultValue;
}
Type Property::type()
{
    return m_type;
}
void Property::setType(Type T)
{
    m_type = T;
}

