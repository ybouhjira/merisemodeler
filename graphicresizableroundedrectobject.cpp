#include "graphicresizableroundedrectobject.h"

// Qt
#include <QGraphicsSceneMouseEvent>
#include <QCursor>

const qreal GraphicResizableRoundedRectObject::PADDING = 6;

GraphicResizableRoundedRectObject::GraphicResizableRoundedRectObject(
        qreal x,
        qreal y,
        qreal width,
        qreal height,
        qreal radius,
        QGraphicsItem* parent)
    : GraphicRoundedRectObject(x, y, width, height, radius, parent)
    , m_mode(None)
    , m_grabingPoint()
{
    setAcceptHoverEvents(true);
}

void GraphicResizableRoundedRectObject::hoverMoveEvent(QGraphicsSceneHoverEvent *event) {
    qreal x = event->pos().x(), y= event->pos().y();

    if((-PADDING < x && x < PADDING)
            || (width() - PADDING < x && x < width() + PADDING) )
        setCursor(QCursor(Qt::SizeHorCursor));
    else if((-PADDING < y && y < PADDING)
            || (height() - PADDING < y && y < height() + PADDING) )
        setCursor(QCursor(Qt::SizeVerCursor));
    else
        setCursor(QCursor());
}

void GraphicResizableRoundedRectObject::hoverLeaveEvent(QGraphicsSceneHoverEvent *) {
    setCursor(QCursor());
}

void GraphicResizableRoundedRectObject::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    qreal x = event->pos().x(), y= event->pos().y();

    if( width() - PADDING < x && x < width() + PADDING)
        m_mode = ResizeRight;
    else if ( -PADDING < x && x < PADDING )
        m_mode = ResizeLeft;
    else if( -PADDING < y && y < PADDING )
        m_mode = ResizeTop;
    else if(height() - PADDING < y && y < height() + PADDING )
        m_mode = ResizeBottom;
    else{
        m_mode = Move;
        m_grabingPoint.setX(x);
        m_grabingPoint.setY(y);
    }
}

void GraphicResizableRoundedRectObject::mouseReleaseEvent(QGraphicsSceneMouseEvent *) {
    m_mode = None;
}

void GraphicResizableRoundedRectObject::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    qreal x = event->pos().x(), y = event->pos().y();
    prepareGeometryChange();
    switch(m_mode) {
    case ResizeTop:
        setHeight(height() - y);
        setY(mapToParent(event->pos()).y());
        break;
    case ResizeBottom:
        setHeight(y);
        break;
    case ResizeRight:
        setWidth(x);
        break;
    case ResizeLeft:
        setWidth(width() - x);
        setX(mapToParent(event->pos()).x());
        break;
    case Move:
        setPos(mapToParent(event->pos() - m_grabingPoint).x(),
               mapToParent(event->pos() - m_grabingPoint).y());
    }
}
