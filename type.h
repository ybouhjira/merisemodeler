#ifndef TYPE_H
#define TYPE_H

#include <QString>
/**
 * @brief The Type class
 */
class Type
{
    //METHODS
public:
    /**
     * @brief returns the name of the type
     */
    QString name();

    /**
     * @brief Modifies the name of the property
     * @param name
     */
    void setName(QString const &name);

protected:
    /**
     * @brief Constructs a type of a property
     * @param name : name of the type
     */
    Type(QString const &name);

    /**
     * @brief Destructs a type
     */
    virtual ~Type();

    //ATTRIBUTS
private:
    QString m_name;
};

#endif // TYPE_H
