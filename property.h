#ifndef PROPERTY_H
#define PROPERTY_H

#include <QString>
#include "type.h"

/**
 * @brief La classe property represente une propriété ou colonne
 */
class Property
{
    //METHODS
public:
    /**
     * @brief Constructeur
     * @param name Nom
     * @param obligatory Indique que la propriété doit avoir une valeur
     * @param check Condition que la valeur de cette propriété doit admettre
     * @param defaultValue Valeur par default
     * @param type Type
     */
    Property(QString const &name,
             Type type,
             bool obligatory = false,
             QString const &check = "",
             QString const &defaultValue = "",
             bool identifiant = false);

    /**
     * @brief Destructeur
     */
    virtual ~Property();

    /**
     * @brief Accesseur
     * @return Nom
     */
    QString name();

    /**
     * @brief Mutateur
     * @param name Nom
     */
    void setName(QString const &name);

    /**
     * @brief Accesseur
     * @return Valeur est obligatoire
     */
    bool obligatory();

    /**
     * @brief Mutateur
     * @param Valeur est obligatoire
     */
    void setObligatory(bool obligatory);

    /**
     * @brief Accesseur
     * @return Identifiant
     */
    bool identifiant();

    /**
     * @brief
     */
    void setIdentifiant();

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
    Type type();

    /**
     * @brief Modifies the type of the property
     */
    void setType(Type type);

    //ATTRIBUTS
private:
    /**
     * @brief Nom
     */
    QString m_name;

    /**
     * @brief Type
     */
    Type m_type;

    /**
     * @brief Obligatoire
     */
    bool m_obligatory;

    /**
     * @brief Valeur par default
     */
    QString m_defaultValue;

    /**
     * @brief Est un identifiant
     */
    bool m_identifiant;

    /**
     * @brief Condition
     */
    QString m_check;

};

#endif // PROPERTY_H
