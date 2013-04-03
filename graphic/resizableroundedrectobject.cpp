#include "resizableroundedrectobject.h"

// Qt
#include <QGraphicsSceneMouseEvent>
#include <QCursor>
#include <QGraphicsScene>

using namespace Graphic;

const qreal ResizableRoundedRectObject::PADDING = 6;

ResizableRoundedRectObject::ResizableRoundedRectObject(
        qreal x,
        qreal y,
        qreal width,
        qreal height,
        qreal radius,
        QGraphicsItem* parent)
    : RoundedRectObject(x, y, width, height, radius, parent)
    , m_mode(None)
    , m_grabingPoint()
{
    setAcceptHoverEvents(true);
}

void ResizableRoundedRectObject::hoverMoveEvent(QGraphicsSceneHoverEvent *event) {
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

void ResizableRoundedRectObject::hoverLeaveEvent(QGraphicsSceneHoverEvent *) {
    setCursor(QCursor());
}

void ResizableRoundedRectObject::mousePressEvent(QGraphicsSceneMouseEvent *event) {
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

        if(!isSelected())
            RoundedRectObject::mousePressEvent(event);
    }
}

void ResizableRoundedRectObject::mouseReleaseEvent(QGraphicsSceneMouseEvent *) {
    m_mode = None;
}

void ResizableRoundedRectObject::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    qreal x = event->pos().x(), y = event->pos().y();
    prepareGeometryChange();
    switch(m_mode) {
    case ResizeTop:
        setHeight(height() - y);
        setY(mapToParent(event->pos()).y());
        emit heightChanged();
        break;
    case ResizeBottom:
        setHeight(y);
        emit heightChanged();
        break;
    case ResizeRight:
        setWidth(x);
        emit widthChanged();
        break;
    case ResizeLeft:
        setWidth(width() - x);
        emit widthChanged();
        setX(mapToParent(event->pos()).x());
        break;
    case Move:
        qreal dx = mapToParent(event->pos() - m_grabingPoint).x() - this->x();
        qreal dy = mapToParent(event->pos() - m_grabingPoint).y() - this->y();
        moveBy(dx, dy);
        foreach (QGraphicsItem* item, scene()->selectedItems()) {
            if(item != this) {
                item->moveBy(dx, dy);
            }
        }
    }
}
