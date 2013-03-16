#include "maxsizetype.h"

MaxSizeType::MaxSizeType(int length,QString const &name)
    : Type(name)
    , m_length(length)
{
}
MaxSizeType::~MaxSizeType()
{
}
int MaxSizeType::length()
{
    return m_length;
}
void MaxSizeType::setLength(int length)
{
    m_length = length;
}
