#ifndef ITEM_H
#define ITEM_H

#include <QString>
#include <QList>
#include "property.h"

class Item
{
    //METHODS
public:

    /**
     * @brief returns the name of the item
     * @return QString
     */
    QString name() const;

    /**
     * @brief Modifies the name of the item
     * @param name
     */
    void setName(QString const &name);

    /**
     * @brief Add a property to the item
     * @param property : pointer of the property
     */
    void addProperty(Property* property);

    /**
     * @brief  remove a property from the item
     * @param index : index of the property
     */
    void removeProperty(int index);

    /**
     * @brief remove a property from the item
     * @param property : pointer of the property
     */
    void removeProperty(Property* property);

    /**
     * @brief Accesseur
     * @return Les properiétés
     */
    QList<Property*> properties();

protected:
    /**
     * @brief Constructs an item with a name
     * @param Name : name of the item
     */
    Item(QString const &Name);

    /**
     * @brief Destroys the item
     */
    virtual ~Item();

    //ATTRIBUTS
private:
    /**
     * @brief name of the item
     */
    QString m_name;
    QList<Property*> m_properties;

};

#endif // ITEM_H
