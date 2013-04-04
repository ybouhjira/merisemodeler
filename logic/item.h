#ifndef ITEM_H
#define ITEM_H

#include "logic/namespace.h"
#include "graphic/object.h"
#include "logic/uniqueconstraint.h"
#include "pugixml/pugixml.hpp"
// Qt
#include <QString>
#include <QList>
#include <QObject>



class Logic::Item : public QObject
{
    Q_OBJECT
    //METHODS
public:

    /**
     * @brief returns the name of the item
     * @return QString
     */
    QString name() const;

    /**
     * @brief Retourne la reprerésentation de l'élément
     */
    virtual Graphic::Object* graphicObject() const = 0 ;

    /**
     * @brief Accesseur
     * @return Les properiétés
     */
    QList<Logic::Property*> properties();

    /**
     * @brief Mutateur
     * @return Les properiétés
     */
    void setProperties(QList<Logic::Property*> properties);

    /**
     * @brief Destroys the item
     */
    virtual ~Item();

    //Reimplemented functions from Class Serializable
    pugi::xml_node toXml(){
        pugi::xml_node node;
        return node;
    }
    Item* fromXml(pugi::xml_node item)
    {
        if(item.empty())
        {
            Logic::Item *i;
            return i;
        }
    }


public slots:

    /**
     * @brief Modifies the name of the item
     * @param name
     */
    void setName(QString const &name);

    /**
     * @brief Add a property to the item
     * @param property : pointer of the property
     */
    void addProperty(Logic::Property* property);

    /**
     * @brief  remove a property from the item
     * @param index : index of the property
     */
    void removeProperty(int index);

    /**
     * @brief remove a property from the item
     * @param property : pointer of the property
     */
    void removeProperty(Logic::Property* property);

signals:
    /**
     * @brief Nom changé
     */
    void nameChanged();

    /**
     * @brief Properietes changées
     */
    void propertiesEdited();
protected:
    /**
     * @brief Constructs an item with a name
     * @param Name : name of the item
     */
    Item(QString const &Name);

    /**
     * @brief writeProperties
     * @return
     */
    pugi::xml_node writeProperties();

    /**
     * @brief writeUK
     * @return
     */
    pugi::xml_node writeUK(QList<Logic::UniqueConstraint *> uniqueConstraints);

    //ATTRIBUTS
private:
    /**
     * @brief name of the item
     */
    QString m_name;
    QList<Property*> m_properties;

};

#endif // ITEM_H
