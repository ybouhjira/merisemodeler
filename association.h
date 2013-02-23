#ifndef ASSOCIATION_H
#define ASSOCIATION_H

#include <QString>
#include <QList>
#include "entity.h"
#include "cardinality.h"

/**
 * @brief La classe Association decris le lien sémantique entre 2 entités
 */
class Association : public Item
{
public:
    /**
     * @brief Construire un objet Association avec un nom et tableau des entités
     * @param name : nom de l'association
     */
    Association(QString const &name
                ,Cardinality* cardinality
                ,Entity* entity1
                ,Entity* entity2);

    /**
     * @brief Destruction de l'association
     */
    virtual ~Association();

    /**
     * @brief modifier une entité
     * @param index : position de l'entité
     * @param entity
     */

    /**
     * @brief Modificateur de l'entité 1
     * @param entity
     */
    void setEntity1(Entity* entity);

    /**
     * @brief Modificateur de l'entité 2
     * @param entity
     */
    void setEntity2(Entity* entity);

    /**
     * @brief Accesseur de l'entité 1
     * @return
     */
    Entity* entity1();

    /**
     * @brief Accesseur de l'entité 2
     * @return
     */
    Entity* entity2();

   /**
    * @brief retourne la cardinalté
    */
   Cardinality* cardinality();

   /**
    * @brief Modifier une cardinalité
    */
   void setCardinality(Cardinality* cardinality);

private:
    Cardinality *m_cardinality;
    Entity *m_entity1;
    Entity *m_entity2;



};

#endif // ASSOCIATION_H
