#ifndef ENTITY_H
#define ENTITY_H

#include "item.h"
#include "uniqueconstraint.h"
#include "graphicentity.h"

// Qt
#include <QList>
#include <QString>

/**
 * @brief Cette classe représente un entité dans le model MCD. Elle contient les
 * données de l'entité et n'a aucune relation avec sa representation graphique
 */
class Entity : public Item
{
    //METHODS
public:
    /**
     * @brief Constructeur
     * @param name : Nom de l'entité
     * @param uniqueConstraints : Contraints de type UNIQUE
     */
    Entity(QString const &name
           , QList<Entity*> parents = QList<Entity*>()
           , QList<UniqueConstraint*> uniqueConstraints = QList<UniqueConstraint*>()
           );

    /**
     * @brief Destructeur
     */
    virtual ~Entity();

    // Redefinitions
    /**
     * @reimp Item::graphicObject()
     */
    GraphicEntity* graphicObject() const ;

    // Accesseurs et mutataurs

    /**
     * @brief Mutateur
     * @param gEntity GraphicEntity representant cette entité
     */
    void setGraphicObject(GraphicEntity* gEntity);

    /**
     * @brief Ajouter un parent a l'entité
     */
    void addParent(Entity *parent);

    /**
     * @brief Supprimer un parent
     * @param index Indice du parent
     */
    void removeParent(int index);

    /**
     * @brief Supprimer un parent
     * @param parent Parent a supprimer
     */
    void removeParent(Entity* parent);

    /**
     * @brief retourne une liste des parents de l'entité
     */
    QList<Entity*> parents();

    /**
     * @brief retourne si l'entité a des parents ou non
     */

    bool hasParents();

    /**
     * @brief retourne une liste des contraints uniques de l'entité
     */
    QList<UniqueConstraint*> uniqueConstraints();

    /**
     * @brief ajouter une contrainte unique a l'entité
     */
    void addUniqueConstraint(UniqueConstraint* uniqueConstraint);

    /**
     * @brief Supprimer une contrainte UNIQUE
     */
    void removeUniqueConstraint(int index);

    /**
     * @brief Supprimer une contrainte UNIQUE
     */
    void removeUniqueConstraint(UniqueConstraint* uniqueConstraint);

    //ATTRIBUTS
private:
    /**
     * @brief Entités des quelles cette entité hérite
     */
    QList<Entity*> m_parents;

    /**
     * @brief Contraintes de type UNIQUE
     */
    QList<UniqueConstraint*> m_uniqueConstraints;

    /**
     * @brief Representation graphique
     */
    GraphicEntity* m_graphicEntity;

};

#endif // ENTITY_H
