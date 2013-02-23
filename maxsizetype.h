#ifndef MAXSIZETYPE_H
#define MAXSIZETYPE_H

#include <QString>
#include "type.h"

class MaxSizeType : public Type
{
//METHODS
public:
    /**
     * @brief Constructs a MaxSizeType
     * @param length : length of the type
     * @param name : name of the type
     */
    MaxSizeType(int length,QString const &name);

    /**
     * @brief destructs a MaxSizeType
     */
    virtual ~MaxSizeType();

    /**
     * @brief returns the length of the type
     */
    int length();

    /**
     * @brief Modifies the length of the type
     * @param length
     */
    void setLength(int length);

//ATTRIBUTS
private:
    int m_length;
};

#endif // MAXSIZETYPE_H
