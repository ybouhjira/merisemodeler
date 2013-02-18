#ifndef ASSOCIATION_H
#define ASSOCIATION_H

#include <QString>
#include <QList>
#include <entity.h>
#include <cardinality.h>

class Association : public Item
{
public:
    /**
     * @brief Constructs an Association
     * @param name : name of the association
     */
    Association(QString const &name,Entity* entities);

    /**
     * @brief Destructs an association
     */
    virtual ~Association();

    /**
     * @brief Modifies an entity
     * @param index
     * @param entity
     */
    void setEntity(int index,Entity* entity);

    /**
     * @brief returns the list of the entities
     */
   Entity* entities();

   /**
    * @brief returns the cardinality
    */
   Cardinality* cardinality();

   /**
    * @brief Modifies the cardinality
    */
   void setCardinality(Cardinality* cardinality);

private:
    Entity m_entities[2];
    Cardinality *m_cardinality;


};

#endif // ASSOCIATION_H
