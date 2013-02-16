#ifndef NUMERIQUETYPE_H
#define NUMERIQUETYPE_H

#include <QString>
#include <maxsizetype.h>

class NumeriqueType : public MaxSizeType
{
    //METHODS
public:
    /**
     * @brief Constructs a NumeriqueType
     * @param name : name of the type
     * @param length : length of the type
     * @param precision : precision of the type
     */
    NumeriqueType(QString const &name, int length, int precision);

    /**
     * @brief destructs a numeriqueType
     */
    virtual ~NumeriqueType();

    /**
     * @brief returns the precision
     */
    int precision();

    /**
     * @brief Modifies the pecision of the numeriqueType
     */
    void setPrecision(int precision);

    //ATTRIBUTS
private:
    int m_precision;
};

#endif // NUMERIQUETYPE_H
