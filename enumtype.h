#ifndef ENUMTYPE_H
#define ENUMTYPE_H

#include "type.h"
#include <QString>
#include <QList>

class EnumType : public Type
{
public:
    /**
     * @brief Constructs a EnumType
     * @param values : the values of the enumeration
     * @param name : name of the EnumType
     */
    EnumType(QList<QString> values, QString const &name);

    /**
     * @brief Destructs the EnumType
     */
    virtual ~EnumType();

    /**
     * @brief add a Value to the EnumType
     * @param value
     */
    void addValue(QString const &value);

    /**
     * @brief remove a Value from the EnumType
     * @param value
     */
    void removeValue(QString const &value);

    /**
     * @brief remove a Value from the EnumType
     * @param value
     */
    void removeValue(int index);

    /**
     * @brief return the value at the position index
     */
    QString valueAt(int index);

    /**
     * @brief returns the index of the value passed by parameter
     */
    int indexOf(QString const &value);

    /**
     * @brief returns a list of the values of the EnumType
     */
    QList<QString> values();


private:
    QList<QString> m_values;
};

#endif // ENUMTYPE_H
