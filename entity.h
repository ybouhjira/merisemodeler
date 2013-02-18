#ifndef ENTITY_H
#define ENTITY_H

#include <item.h>
#include <uniqueconstraint.h>
#include <identifier.h>
#include <QList>
#include <QString>

class Entity : public Item
{
public:
    /**
     * @brief Constructs an Entity
     * @param name : name of the entity
     * @param uniqueConstraints : unique Constraints
     * @param Identifier : identifier of the entity
     */
    Entity(QString const &name
           , QList<Entity*> parents = QList<Entity*>()
           , auto uniqueConstraints = QList<UniqueConstraint*>()
           , Identifier * identifier);

    /**
     * @brief Desctructs an entity
     */
    virtual ~Entity();

    /**
     * @brief Add a parent to the entity
     */
    void addParent(Entity *parent);

    /**
     * @brief removes a parent
     */
    void removeParent(int index);

    /**
     * @brief removes a parent
     */
    void removeParent(Entity* parent);

    /**
     * @brief returns a list of the parents ofthe entity
     */
    QList<Entity*> parents();

    /**
     * @brief returns the list of the unique Constraints of the entity
     */
    QList<UniqueConstraint*> uniqueConstraints();

    /**
     * @brief returns the identifier of the entity
     */
    Identifier* identifier();

    /**
     * @brief Modifies the identifier of the entity
     */
    void setIdentifier(Identifier* identifier);

    /**
     * @brief add an Unique Constraint to the entity
     */
    void addUniqueConstraint(UniqueConstraint* uniqueConstraint);

    /**
     * @brief remove an Unique Constraint
     */
    void removeUniqueConstraint(int index);

    /**
     * @brief remove an Unique Constraint
     */
    void removeUniqueConstraint(UniqueConstraint* uniqueConstraint);


private:
    QList<Entity*> m_parents;
    QList<UniqueConstraint*> m_uniqueConstraints;
    Identifier *m_identifier;

};

#endif // ENTITY_H
