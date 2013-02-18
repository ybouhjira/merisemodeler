#ifndef UNIQUECONSTRAINT_H
#define UNIQUECONSTRAINT_H

class UniqueConstraint : public MultiPropertyConstraint
{
public:
    /**
     * @brief Constructs an Unique Constraint
     */
    UniqueConstraint();

    /**
     * @brief Destructs an Unique Constraint
     */
    virtual ~UniqueConstraint();
};

#endif // UNIQUECONSTRAINT_H
