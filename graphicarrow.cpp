#include "graphicarrow.h"
#include "graphicstyle.h"

// Qt
#include <QPainter>
#include <QGraphicsItem>
#include <QPainterPath>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>

// PRIVATE
QPointF GraphicArrow::findSourcePoint() const {
    QPointF s = m_source->shape().pointAtPercent(m_positionOnSource);
    return mapFromItem(m_source,s) ;
}

QPointF GraphicArrow::findDestPoint() const {
    QPointF d = m_destination->shape().pointAtPercent(m_positionOnDestionation);
    return mapFromItem(m_destination,d) ;
}

// CONSTRUCTEUR
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
  , m_displayHandels(false)
  , m_movingSource(false)
  , m_movingDestination(false)
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
    QPointF s = findSourcePoint();
    QPointF d = findDestPoint();
    painter->drawLine(s, d);

    // Handlers
    if(m_displayHandels) {
        painter->setBrush(Qt::black);
        painter->drawRect(QRectF(s - QPointF(2.5, 2.5), QSizeF(5,5)) );
        painter->drawRect(QRectF(d  - QPointF(2.5, 2.5), QSizeF(5,5)) );
    }
}

QRectF GraphicArrow::boundingRect() const {
    QPointF s = findSourcePoint() ;
    QPointF d = findDestPoint() ;

    QPointF topLeft(
                ((s.x() < d.x())? s.x() : d.x()) - 2.5,
                ((s.y() < d.y())? s.y() : d.y()) - 2.5
                );

    QPointF bottomRight(
                ((s.x() > d.x())? s.x() : d.x()) + 2.5,
                ((s.y() > d.y())? s.y() : d.y()) + 2.5
                );

    return QRectF(topLeft, bottomRight);
}

QPainterPath GraphicArrow::shape() const {
    QPointF s = findSourcePoint() ;
    QPointF d = findDestPoint() ;

    QPainterPath path(s);
    path.lineTo(d);

    // Pour inclure la largeur du trait
    QPainterPathStroker stroker;
    stroker.setWidth(style()->pen().width());
    return stroker.createStroke(path);
}

// EVENTS
void GraphicArrow::hoverEnterEvent(QGraphicsSceneHoverEvent *) {
    m_displayHandels = true ;
    update(boundingRect());
}

void GraphicArrow::hoverLeaveEvent(QGraphicsSceneHoverEvent *) {
    m_displayHandels = false ;
    update(boundingRect());
}

void GraphicArrow::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    QPointF center = m_source->boundingRect().center() ;

    if(m_movingSource)
        m_positionOnSource = QLineF(center,event->pos()).angle() / 360;
    else if(m_movingDestination)
        m_positionOnDestionation = QLineF(center, event->pos()).angle() / 360;
    redraw();
}

void GraphicArrow::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    QPointF pos = event->pos();

    if(QLineF(findSourcePoint(), pos).length() < 6) {
        m_movingSource = true;
    }else if(QLineF(findDestPoint(), pos).length() < 6) {
        m_movingDestination = true;
    }else{
        m_movingSource = false;
        m_movingDestination = false;
    }
}

// ACCESSEURS ET MUTATEURS
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
