#ifndef LOGIC_PARAMETERLESSTYPEFACTORY_H
#define LOGIC_PARAMETERLESSTYPEFACTORY_H

#include "namespace.h"

// Qt
#include <QStringList>
#include <QObject>

class Logic::TypeFactory
{
    // METHODES
public:
    // static
    /**
     * @return Retourne la liste des types disponible
     */
    static QStringList meriseTypes() ;

    // non static
    /**
     * @brief Constructeur
     * @param typeString chaine de caractères decrivant le type
     */
    TypeFactory(QString const& typeString );


    Logic::Type buildType() const;

    // ATTRIBUTS
private:
    // static
    static const QStringList m_meriseTypes ;

    // non-static
    /**
     * @brief chaine de caractères decrivant le type
     */
    QString m_typeString;
};

#endif // LOGIC_PARAMETERLESSTYPEFACTORY_H
