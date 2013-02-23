#ifndef CARDINALITY_H
#define CARDINALITY_H

#include "entity.h"

/**
 * @brief La classe cardinalité décris sert à compter le nombre minimum et
 * maximum de possibilités que chaque classe contient dans la relation liant
 * 2 ou plusieurs objets.
 */
class Cardinality
{
    // TYPES
    /**
     * @brief Enumération des valeurs que peut prendre une cardinalité
     */
    enum Value {
        Zero, //< 0
        One, //< 1
        N  //< n
    };

    // METHODS
public:

    /**
     * @brief Constructeur
     * @param max Valeur maximum
     * @param min Valeur minimum
     */
    Cardinality(Value max, Value min);

    /**
     * @brief Destructeur
     */
    virtual ~Cardinality();

    // Accesseur et mutateurs
    /**
     * @brief Accesseur
     * @return Valeur maximum
     */
    Value max();

    /**
     * @brief Accesseur
     * @return Valeur minimum
     */
    Value min();

    /**
     * @brief Mutateur
     * @param max Valeur maximum
     */
    void setMax(Value max);

    /**
     * @brief Mutateur
     * @param min Valeur minimum
     */
    void setMin(Value min);

    /**
     * @brief Accesseur
     * @return L'entité
     */
    Entity* entity();

    /**
     * @brief Mutateur
     * @param entity L'entité
     */
    void setEntity(Entity* entity);

    //ATTRIBUTS
private:
    /**
     * @brief Valeur maximum
     */
    Value m_max;
    /**
     * @brief Valeur minimum
     */
    Value m_min;
    /**
     * @brief entité
     */
    Entity *m_entity;
};

#endif // CARDINALITY_H
