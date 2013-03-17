#include "typefactory.h"
#include "type.h"
#include "invalidtypestringexception.h"

using namespace Logic;

const QStringList TypeFactory::m_meriseTypes = QStringList (
    {
        QObject::tr("Date"),
        QObject::tr("Text")
    }
);

QStringList TypeFactory::meriseTypes() {
    return m_meriseTypes ;
}

TypeFactory::TypeFactory(QString const& typeString)
    : m_typeString(typeString)
{
}

Type TypeFactory::buildType() const {
    if(m_typeString.isEmpty())
        return Type(QObject::tr("Text"));
    if(!m_meriseTypes.contains(m_typeString))
        throw InvalidTypeStringException();
    return Type(m_typeString);
}
