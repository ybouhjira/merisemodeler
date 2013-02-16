#include "enumtype.h"

EnumType::EnumType(QList<QString> *values, const QString &name)
    : Type(name)
    , m_values(new QList<QString*>(values))
{
}
EnumType::~Type()
{
}

void EnumType::addValue(const QString &value)
{
    m_values.append(value);
}
void EnumType::removeValue(int index)
{
    m_values.removeAt(index);
}
void EnumType::removeValue(const QString &value)
{
    m_values.removeOne(value);
}
int EnumType::indexOf(const QString &value)
{
    return m_values.indexOf(value);
}
QString* EnumType::valueAt(int index)
{
    return m_values.at(index);
}
QList<QString*> EnumType::values()
{
    return m_values;
}



