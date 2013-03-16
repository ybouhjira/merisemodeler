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
             bool isObligatory = false,
             QString const &check = "",
             QString const &defaultValue = "",
             bool isIdentifier = false);

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
    bool isObligatory();

    /**
     * @brief Mutateur
     * @param Valeur est obligatoire
     */
    void setIsObligatory(bool isObligatory);

    /**
     * @brief Accesseur
     * @return Identifiant
     */
    bool isIdentifier() const;

    /**
     * @brief
     */
    void setIsIdentifier(bool isIndetifier);

    /**
     * @brief returns the check condition
     */
    QString check() const;

    /**
     * @brief Modifies the check condition
     */
    void setCheck(QString const &check);

    /**
     * @brief returns the default value
     */
    QString defaultValue() const;

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
    bool m_isObligatory;

    /**
     * @brief Valeur par default
     */
    QString m_defaultValue;

    /**
     * @brief Est un identifiant
     */
    bool m_isIdentifier;

    /**
     * @brief Condition
     */
    QString m_check;

};

#endif // PROPERTY_H
