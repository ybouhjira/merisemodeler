#include "graphicarrow.h"
#include "graphicstyle.h"

// Qt
#include <QPainter>
#include <QGraphicsItem>
#include <QPainterPath>
#include <QGraphicsRectItem>

GraphicArrow::GraphicArrow(
        QGraphicsObject *source,
        QGraphicsObject *destination,
        qreal positionOnSource,
        qreal positionOnDestination,
        QGraphicsItem *parent) :
    GraphicObject(parent)
  , m_source(source)
  , m_destination(destination)
  , m_positionOnSource(positionOnSource)
  , m_positionOnDestionation(positionOnDestination)
{
    // Parametres
    setAcceptHoverEvents(true);

    // Connections
    connect(m_source, SIGNAL(xChanged()), this, SLOT(redraw()) );
    connect(m_source, SIGNAL(yChanged()), this, SLOT(redraw()) );
    connect(m_destination, SIGNAL(xChanged()), this, SLOT(redraw()) );
    connect(m_destination, SIGNAL(yChanged()), this, SLOT(redraw()) );
}

GraphicArrow::~GraphicArrow() {
}

void GraphicArrow::paint
(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    GraphicObject::paint(painter, option, widget);
    QPointF s = m_source->shape().pointAtPercent(m_positionOnSource);
    QPointF d = m_destination->shape().pointAtPercent(m_positionOnDestionation);
    painter->drawLine(mapFromItem(m_source,s), mapFromItem(m_destination,d));

    // Handlers
    painter->setRenderHint(QPainter::Antialiasing, false);
    painter->setBrush(Qt::black);
    painter->drawRect(QRectF(
                          mapFromItem(m_source,s) - QPointF(2.5, 2.F),
                          QSizeF(5,5)
                          ));

    painter->drawRect(QRectF(
                          mapFromItem(m_destination,d)  - QPointF(2.5, 2.F),
                          QSizeF(5,5)
                          ));

}

QRectF GraphicArrow::boundingRect() const {

    QPointF s = m_source->shape().pointAtPercent(m_positionOnSource);
    QPointF d = m_destination->shape().pointAtPercent(m_positionOnDestionation);

    s = mapFromItem(m_source,s) ;
    d = mapFromItem(m_destination,d) ;

    QPointF topLeft(
                ((s.x() < d.x())? s.x() : d.x()) - 5,
                ((s.y() < d.y())? s.y() : d.y()) - 5
                );

    QPointF bottomRight(
                ((s.x() > d.x())? s.x() : d.x()) + 5,
                ((s.y() > d.y())? s.y() : d.y()) + 5
                );

    return QRectF(topLeft, bottomRight);
}

QPainterPath GraphicArrow::shape() const {
    QPointF s = m_source->shape().pointAtPercent(m_positionOnSource);
    QPointF d = m_destination->shape().pointAtPercent(m_positionOnDestionation);

    s = mapFromItem(m_source,s) ;
    d = mapFromItem(m_destination,d) ;

    QPainterPath path(s);
    path.lineTo(d);

    // Pour inclure la largeur du trait
    QPainterPathStroker stroker;
    stroker.setWidth(style()->pen().width());

    return stroker.createStroke(path);
}

QGraphicsObject* GraphicArrow::source() const {
    return m_source;
}

QGraphicsObject *GraphicArrow::destination() const {
    return m_destination;
}

qreal GraphicArrow::positionOnSource() const {
    return m_positionOnSource;
}

qreal GraphicArrow::positionOnDestination() const {
    return m_positionOnDestionation;
}

void GraphicArrow::setPositionOnSource(qreal position) {
    m_positionOnSource  = position ;
}

void GraphicArrow::setPositionOnDestination(qreal position) {
    m_positionOnDestionation = position;
}

void GraphicArrow::redraw() {
    prepareGeometryChange();
    update(boundingRect());


}
