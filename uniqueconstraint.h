#ifndef UNIQUECONSTRAINT_H
#define UNIQUECONSTRAINT_H

#include "multipropertyconstraint.h"

class UniqueConstraint : public MultiPropertyConstraint
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
};

#endif // UNIQUECONSTRAINT_H
