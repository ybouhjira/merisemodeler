#ifndef PROPERTY_H
#define PROPERTY_H

#include <QString>
#include <type.h>

class Property
{
    //METHODS
public:
    /**
     * @brief Constructs a property
     * @param name : name of the property
     * @param obligatory : This attribute holds whether this property is
     * obligatory or not.
     * @param check : check condition
     * @param defaultValue : a default Value of an attribut
     * @param type : type of the attribut
     */
    Property(QString const &name,
             Type *type,
             bool obligatory=false,
             QString const & check="",
             QString const &defaultValue="");

    /**
     * @brief Destructs the property
     */
    virtual ~Property();

    /**
     * @brief returns the name of the property
     */
    QString name();

    /**
     * @brief Modifies the name of the property
     */
    void setName(QString const &name);

    /**
     * @brief returns if the property is obligatory or not
     */
    bool obligatory();

    /**
     * @brief Modifies the obligatory attribute
     */
    void setObligatory(bool);

    /**
     * @brief returns the check condition
     */
    QString check();

    /**
     * @brief Modifies the check condition
     */
    void setCheck(QString const &check);

    /**
     * @brief returns the default value
     */
    QString defaultValue();

    /**
     * @brief Modifies the default value
     */
    void setDefaultValue(QString const &defaultValue);

    /**
     * @brief returns the type of the property
     */
    Type* type();

    /**
     * @brief Modifies the type of the property
     */
    void setType(Type* type);

    //ATTRIBUTS
private:
    QString m_name;
    bool m_obligatory;
    QString m_check;
    QString m_defaultValue;
    Type *m_type;
};

#endif // PROPERTY_H
