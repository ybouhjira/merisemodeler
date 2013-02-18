#ifndef CARDINALITY_H
#define CARDINALITY_H

#include <entity.h>
#include <association.h>

class Cardinality
{
    //METHODS
public:
    /**
     * @brief enumeration of the different values of a cardinality
     */
    enum value{One,Zero,N};

    /**
     * @brief Constructs a cardinality
     * @param max
     * @param min
     */
    Cardinality(value max,value min);

    /**
     * @brief Destructs a Cardinality
     */
    virtual ~Cardinality();

    /**
     * @brief returns the max value of the cardinality
     */
    value max();

    /**
     * @brief returns the min value of the cardinality
     */
    value min();

    /**
     * @brief modifies the max value of the cardinality
     */
    void setMax(value Value);

    /**
     * @brief Modifies th Min value of the cardinality
     */
    void setMin(value Value);

    /**
     * @brief returns the entity related to the cardinality
     */
    Entity* entity();

    /**
     * @brief Modifies the entity
     */
    void setEntity(Entity* entity);



    //ATTRIBUTS
private:
    value m_max;
    value m_min;
    Entity *m_entity;

};

#endif // CARDINALITY_H
