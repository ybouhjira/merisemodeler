#ifndef ITEM_H
#define ITEM_H

#include "logic/namespace.h"
#include "graphic/object.h"
#include "xml/serializable.h"
#include "logic/uniqueconstraint.h"

// Qt
#include <QString>
#include <QList>
#include <QObject>


class Logic::Item : public QObject, public Serializable
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
     * @brief Destroys the item
     */
    virtual ~Item();

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
     * @brief
     * @return
     */
    xml_node toXml();
    void fromXml(xml_node entity);
    /**
     * @brief writeProperties
     * @return
     */
    xml_node writeProperties();

    /**
     * @brief writeUK
     * @return
     */
    xml_node writeUK(QList<UniqueConstraint *> uniqueConstraints);

    //ATTRIBUTS
private:
    /**
     * @brief name of the item
     */
    QString m_name;
    QList<Property*> m_properties;

};

#endif // ITEM_H
