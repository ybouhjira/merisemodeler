#ifndef UNIQUECONSTRAINT_H
#define UNIQUECONSTRAINT_H

#include <QList>
#include "property.h"

class UniqueConstraint
{
public:
    /**
     * @brief Constructs an Unique Constraint
     */
    UniqueConstraint(QList<Property*> properties);

    /**
     * @brief Destructs an Unique Constraint
     */
    virtual ~UniqueConstraint();

    /**
     * @brief returns the list of the properties of the constraint
     */
    QList<Property*> properties();

    /**
     * @brief adds a property
     * @param property
     */
    void addProperty(Property *property);

    /**
     * @brief removes a property
     * @param index
     */
    void removeProperty(int index);

    /**
     * @brief removes a Property
     * @param property
     */
    void removeProperty(Property *property);

    //ATTRIBUTS
private:
    QList<Property*> m_properties;
};

#endif // UNIQUECONSTRAINT_H
