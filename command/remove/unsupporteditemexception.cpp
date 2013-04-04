#include "unsupporteditemexception.h"

using namespace Command;

UnsupportedItemException::UnsupportedItemException(QGraphicsItem* item)
    : m_item(item)
{
}

void UnsupportedItemException::setItem(QGraphicsItem *item) {
    m_item = item;
}

QGraphicsItem* UnsupportedItemException::item() const {
    return m_item;
}
