#ifndef ENTITY_H
#define ENTITY_H

#include "logic/namespace.h"
#include "item.h"
#include "uniqueconstraint.h"
#include "graphic/entity.h"
#include "pugixml/pugixml.hpp"
// Qt
#include <QList>
#include <QString>

/**
 * @brief Cette classe représente un entité dans le model MCD. Elle contient les
 * données de l'entité et n'a aucune relation avec sa representation graphique
 */
class Logic::Entity : public Logic::Item
{
    //METHODS
public:
    /**
     * @brief Constructeur
     * @param name Nom de l'entité
     * @param uniqueConstraints Contraints de type UNIQUE
     */
    Entity( QString const &name,
            QList<Entity*> parents = QList<Entity*>(),
            QList<Logic::UniqueConstraint*> uniqueConstraints = QList<UniqueConstraint*>()
            );

    /**
     * @brief Destructeur
     */
    virtual ~Entity();

    // Redefinitions
    /**
     * @reimp Item::graphicObject()
     */
    Graphic::Entity* graphicObject() const override;

    // Accesseurs et mutateurs
    /**
     * @brief Mutateur
     * @param gEntity GraphicEntity representant cette entité
     */
    void setGraphicObject(Graphic::Entity* gEntity) ;

    /**
     * @brief Ajouter un parent a l'entité
     */
    void addParent(Logic::Entity *parent);

    /**
     * @brief Supprimer un parent
     * @param index Indice du parent
     */
    void removeParent(int index);

    /**
     * @brief Supprimer un parent
     * @param parent Parent a supprimer
     */
    void removeParent(Logic::Entity* parent);

    /**
     * @brief retourne une liste des parents de l'entité
     */
    QList<Logic::Entity*> parents();

    /**
     * @brief retourne une liste des contraints uniques de l'entité
     */
    QList<Logic::UniqueConstraint*> uniqueConstraints();

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

    /**
     * @brief retourne un objet xml_node representant une entité
     * @return xml_node
     */
    pugi::xml_node toXml();

    /**
     * @brief fromXml
     * @param entity
     */
    Logic::Entity* fromXml(pugi::xml_node entity, QList<Item*> items);

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
    Graphic::Entity* m_graphicEntity;

};

#endif // ENTITY_H
