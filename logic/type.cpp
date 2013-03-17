#include "type.h"

using namespace Logic;
Type::Type(QString const &name)
    :m_name(name)
{
}

Type::~Type()
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
