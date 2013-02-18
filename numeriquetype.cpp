#include "numeriquetype.h"

NumeriqueType::NumeriqueType(QString const &name,int length,int precision)
    : maxSizeType(length,name)
    , m_precision(precision)
{
}
NumeriqueType::~NumeriqueType()
{
}

int NumeriqueType::precision()
{
    return m_precision;
}

void NumeriqueType::setPrecision(int precision)
{
    m_precision = precision;
}

