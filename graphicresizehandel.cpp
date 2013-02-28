#include "graphicresizehandel.h"
#include "graphicstyle.h"

const qreal GraphicResizeHandel::RADIUS = 0 ;
const qreal GraphicResizeHandel::SIZE = 5;

GraphicResizeHandel::GraphicResizeHandel(
        qreal x,
        qreal y,
        QGraphicsItem *parent)
    : GraphicRoundedRectObject(
          x,
          y,
          GraphicResizeHandel::SIZE,
          GraphicResizeHandel::SIZE,
          GraphicResizeHandel::RADIUS,
          parent)
{
    setFlag(QGraphicsItem::ItemIsMovable);
    setStyle(new GraphicStyle(QBrush(Qt::black)));
}
