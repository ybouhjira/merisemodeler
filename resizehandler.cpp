#include "resizehandler.h"
// Qt
#include <QBrush>

ResizeHandler::ResizeHandler(QGraphicsItem *parent) :
    QGraphicsRectItem(parent)
{
    setBrush(QBrush(Qt::black));
    setRect(0,0,5,5);
    setAcceptHoverEvents(true);
}
