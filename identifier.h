#ifndef IDENTIFIER_H
#define IDENTIFIER_H

#include<QString>

class Identifier : public MultiPropertyConstraint
{
public:

    /**
     * @brief Constructs an Identifier
     * @param name : name of the constraint
     */
    Identifier();

    /**
     * @brief Destructs an Identifier
     */
    virtual ~Identifier();
};

#endif // IDENTIFIER_H
