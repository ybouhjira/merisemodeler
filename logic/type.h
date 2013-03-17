#ifndef TYPE_H
#define TYPE_H

#include "logic/namespace.h"

#include <QString>
/**
 * @brief Le type d'une propriété
 */
class Logic::Type
{
    //METHODS
public:
    /**
     * @brief returns the name of the type
     */
    QString name() const;

    /**
     * @brief Modifies the name of the property
     * @param name
     */
    void setName(QString const &name);

    /**
     * @brief Constructs a type of a property
     * @param name : name of the type
     */
    Type(QString const &name);

    /**
     * @brief Destructs a type
     */
    virtual ~Type();

    //ATTRIBUTS
private:
    QString m_name;
};

#endif // TYPE_H
