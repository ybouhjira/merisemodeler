#ifndef CARDINALITY_H
#define CARDINALITY_H

#include "logic/namespace.h"
#include <QString>

/**
 * @brief Cette classe représente un lien uniderictionel entre une association
 * et un entité. elle contient les cardinalité minimum et maximum, et un
 * pointeur vers l'entité ciblé
 */
class Logic::Link
{
public:
    // TYPES
    /**
     * @brief Enumération des valeurs que peut prendre une cardinalité
     */
    enum Cardinality {
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
    Link(Logic::Entity* entity, Cardinality max, Cardinality min);

    /**
     * @brief Destructeur
     */
    virtual ~Link();

    // Accesseur et mutateurs
    /**
     * @brief Accesseur
     * @return Valeur maximum
     */
    Cardinality max();

    /**
     * @brief Accesseur
     * @return Valeur minimum
     */
    Cardinality min();

    /**
     * @brief Mutateur
     * @param max Valeur maximum
     */
    void setMax(Cardinality max);

    /**
     * @brief Mutateur
     * @param min Valeur minimum
     */
    void setMin(Cardinality min);

    /**
     * @brief Accesseur
     * @return L'entité
     */
    Logic::Entity* entity();

    /**
     * @brief Mutateur
     * @param entity L'entité
     */
    void setEntity(Logic::Entity* entity);

    static QString cardinalityToString(Cardinality c);
    static Cardinality stringToCardinality(QString c);


    //ATTRIBUTS
private:
    /**
     * @brief Valeur maximum
     */
    Cardinality m_max;

    /**
     * @brief Valeur minimum
     */
    Cardinality m_min;

    /**
     * @brief entité
     */
    Logic::Entity *m_entity;
};

#endif // CARDINALITY_H
