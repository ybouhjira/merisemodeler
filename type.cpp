#include "type.h"

Type::Type(QString const &name)
{
    m_name = name;
}
Type::~Type()
{

}
QString Type::type()
{
    return m_name;
}
void Type::setName(QString const &name)
{
    m_name = name;
}
