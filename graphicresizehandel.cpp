#include "graphicresizehandel.h"
#include "graphicstyle.h"

const qreal GraphicResizeHandel::RADIUS = 0 ;
const qreal GraphicResizeHandel::SIZE = 5;

GraphicResizeHandel::GraphicResizeHandel(
        qreal x,
        qreal y,
        QCursor cursor,
        QGraphicsItem *parent)
    : GraphicRoundedRectObject(
          x - GraphicResizeHandel::SIZE/2,
          y - GraphicResizeHandel::SIZE/2,
          GraphicResizeHandel::SIZE,
          GraphicResizeHandel::SIZE,
          GraphicResizeHandel::RADIUS,
          parent)
    , m_cursor(cursor)
{
    setFlag(QGraphicsItem::ItemIsMovable);
    setStyle(new GraphicStyle(QBrush(Qt::black)));
    setCursor(m_cursor);
}
