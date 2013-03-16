#include "property.h"
Property::Property ( QString const &name
                   , Type type
                   , bool obligatory
                   , QString const &check
                   , QString const &defaultVal
                   , bool identifiant)
    : m_name(name)
    , m_type(type)
    , m_isObligatory(obligatory)
    , m_defaultValue(defaultVal)
    , m_isIdentifier(identifiant)
    , m_check(check)
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

bool Property::isObligatory()
{
    return m_isObligatory;
}

void Property::setIsObligatory(bool obligatory)
{
    m_isObligatory = obligatory;
}

QString Property::check() const
{
    return m_check;
}

void Property::setCheck(QString const &Check)
{
    m_check = Check;
}

QString Property::defaultValue() const
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

bool Property::isIdentifier() const {
  return m_isIdentifier;
}

void Property::setIsIdentifier(bool id) {
    m_isIdentifier = id;
}
