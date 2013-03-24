#include "unsopporteditemexception.h"

using namespace Command;

UnsopportedItemException::UnsopportedItemException(QGraphicsItem* item)
    : m_item(item)
{
}

void UnsopportedItemException::setItem(QGraphicsItem *item) {
    m_item = item;
}

QGraphicsItem* UnsopportedItemException::item() const {
    return m_item;
}
