#ifndef ENTITY_H
#define ENTITY_H

#include "item.h"
#include "uniqueconstraint.h"
#include "identifier.h"
#include <QList>
#include <QString>

/**
 * @brief La classe entité est la représentation d'un élément matériel ou
 * immatériel ayant un rôle dans le système que l'on désire décrire.
 */
class Entity : public Item
{
    //METHODS
public:
    /**
     * @brief Construire une entité
     * @param name : nom de l'entité
     * @param uniqueConstraints : unique Constraints
     * @param Identifier : identifiant de l'entité
     */
    Entity(QString const &name
           , Identifier * identifier
           , QList<Entity*> parents
           , QList<UniqueConstraint*> uniqueConstraints
           );

    /**
     * @brief Desctruction d'une entité
     */
    virtual ~Entity();

    /**
     * @brief Ajouter un parent a l'entité
     */
    void addParent(Entity *parent);

    /**
     * @brief Supprimer un parent
     */
    void removeParent(int index);

    /**
     * @brief Supprimer un parent
     */
    void removeParent(Entity* parent);

    /**
     * @brief retourne une liste des parents de l'entité
     */
    QList<Entity*> parents();

    /**
     * @brief retourne une liste des contraints uniques de l'entité
     */
    QList<UniqueConstraint*> uniqueConstraints();

    /**
     * @brief retourne l'identifiant de l'entité
     */
    Identifier* identifier();

    /**
     * @brief Modifier l'identifiant de l'entité
     */
    void setIdentifier(Identifier* identifier);

    /**
     * @brief ajouter une contrainte unique a l'entité
     */
    void addUniqueConstraint(UniqueConstraint* uniqueConstraint);

    /**
     * @brief Supprimer une contrainte unique
     */
    void removeUniqueConstraint(int index);

    /**
     * @brief Supprimer une contrainte unique
     */
    void removeUniqueConstraint(UniqueConstraint* uniqueConstraint);



    //ATTRIBUTS
private:
    Identifier *m_identifier;
    QList<Entity*> m_parents;
    QList<UniqueConstraint*> m_uniqueConstraints;


};

#endif // ENTITY_H