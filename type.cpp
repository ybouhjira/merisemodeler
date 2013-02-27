#include "type.h"

Type::Type(QString const &name)
    :m_name(name)
{
}
Type::~Type()
{
}
Type::Type()
    :m_name("type")
{

}

QString Type::name() const
{
    return m_name;
}
void Type::setName(QString const &name)
{
    m_name = name;
}
