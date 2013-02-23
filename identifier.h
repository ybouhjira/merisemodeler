#ifndef IDENTIFIER_H
#define IDENTIFIER_H

#include <QString>
#include "property.h"
#include "multipropertyconstraint.h"

class Identifier : public MultiPropertyConstraint
{
public:

    /**
     * @brief Constructs an Identifier
     * @param name : name of the constraint
     */
    Identifier(QList<Property*> properties);

    /**
     * @brief Destructs an Identifier
     */
    virtual ~Identifier();
};

#endif // IDENTIFIER_H
