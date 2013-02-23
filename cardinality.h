#ifndef CARDINALITY_H
#define CARDINALITY_H

#include "entity.h"
#include "value.h"


/**
 * @brief La classe cardinalité décris sert à compter le nombre minimum et
 * maximum de possibilités que chaque classe contient dans la relation liant
 * 2 ou plusieurs objets.
 */
class Cardinality
{
    //METHODS
public:


    /**
     * @brief Construire une cardinalité
     * @param max
     * @param min
     */
    Cardinality(value max,value min);

    /**
     * @brief Destruction d'une cardinalité
     */
    virtual ~Cardinality();

    /**
     * @brief retourne la valeur maximum de la cardinalité
     */
    value max();

    /**
     * @brief retourne la valeur minimum de la cardinalité
     */
    value min();

    /**
     * @brief modifier la valeur maximum de la cardinalité
     */
    void setMax(value Value);

    /**
     * @brief Modifier la valeur minimum de la cardinalité
     */
    void setMin(value Value);

    /**
     * @brief retourne l'entité reliée avec la cardinalité
     */
    Entity* entity();

    /**
     * @brief modifier l'entité reliée avec la cardinalité
     */
    void setEntity(Entity* entity);


    //ATTRIBUTS
private:
    value m_max;
    value m_min;
    Entity *m_entity;

};

#endif // CARDINALITY_H
