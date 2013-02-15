#include "property.h"
Property::Property(QString name, bool obligatory, QString check, QString defaultVal)
{
    m_name = new QString(name);
    m_obligatory = obligatory;
    m_check = check;
    m_defaultValue = defaultVal;
}
Property::~Property()
{
    delete m_type;
}
QString Property::name()
{
    return name;
}
void Property::setName(QString const &Name)
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
Type* Property::Type()
{
    return m_type;
}
void Property::setType(Type *T)
{
    m_type = T;
}

