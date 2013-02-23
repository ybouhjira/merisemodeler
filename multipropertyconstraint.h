#ifndef MULTIPROPERTYCONSTRAINT_H
#define MULTIPROPERTYCONSTRAINT_H

#include "property.h"
#include <QString>
#include <QList>

class MultiPropertyConstraint
{
    //METHODS
public:
    /**
     * @brief Constructs a MultiPropertyConstraint
     * @param name : name of the constraint
     */
    MultiPropertyConstraint(QList<Property *> properties);

    /**
     * @brief Destructs a MultiPropertyConstraint
     */
    virtual ~MultiPropertyConstraint();

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
    QString m_name;
};

#endif // MULTIPROPERTYCONSTRAINT_H
