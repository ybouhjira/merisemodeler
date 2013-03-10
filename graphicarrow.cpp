#include "graphicarrow.h"
#include "graphicstyle.h"

// Qt
#include <QPainter>
#include <QGraphicsItem>
#include <QPainterPath>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QCursor>

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
        GraphicObject *source,
        GraphicObject *destination,
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
    connect(m_source, SIGNAL(heightChanged()), this, SLOT(redraw()) );
    connect(m_source, SIGNAL(widthChanged()), this, SLOT(redraw()));

    connect(m_destination, SIGNAL(xChanged()), this, SLOT(redraw()) );
    connect(m_destination, SIGNAL(yChanged()), this, SLOT(redraw()) );
    connect(m_destination, SIGNAL(heightChanged()), this, SLOT(redraw()) );
    connect(m_destination, SIGNAL(widthChanged()), this, SLOT(redraw()) );
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
        QPointF halfRect(HANDLE_SIZE / 2, HANDLE_SIZE / 2);
        QSize size(HANDLE_SIZE, HANDLE_SIZE);
        painter->drawRect(QRectF(s - halfRect, size));
        painter->drawRect(QRectF(d - halfRect, size));
    }
}

QRectF GraphicArrow::boundingRect() const {
    QPointF s = findSourcePoint() ;
    QPointF d = findDestPoint() ;

    QPointF topLeft(
                ((s.x() < d.x())? s.x() : d.x()) - HANDLE_SIZE / 2,
                ((s.y() < d.y())? s.y() : d.y()) - HANDLE_SIZE / 2
                );

    QPointF bottomRight(
                ((s.x() > d.x())? s.x() : d.x()) + HANDLE_SIZE / 2,
                ((s.y() > d.y())? s.y() : d.y()) + HANDLE_SIZE / 2
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
    stroker.setWidth(HANDLE_SIZE / 2);
    return stroker.createStroke(path);
}

// EVENTS
void GraphicArrow::hoverEnterEvent(QGraphicsSceneHoverEvent *event) {
    m_displayHandels = true ;

    if(QLineF(findSourcePoint(), event->pos()).length() < HANDLE_SIZE)
        setCursor(Qt::SizeAllCursor);
    else if(QLineF(findDestPoint(), event->pos()).length() < HANDLE_SIZE)
        setCursor(Qt::SizeAllCursor);
    else
        setCursor(QCursor());

    update(boundingRect());
}

void GraphicArrow::hoverLeaveEvent(QGraphicsSceneHoverEvent *) {
    m_displayHandels = false ;
    update(boundingRect());
}

void GraphicArrow::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    if (m_movingSource || m_movingDestination) {
        qreal *position;
        GraphicObject* item;

        if(m_movingSource) {
            position = &m_positionOnSource;
            item = m_source;
        } else if(m_movingDestination) {
            position = &m_positionOnDestionation;
            item = m_destination;
        }

        QPointF center = item->boundingRect().center();
        QPointF topLeftCorner = item->boundingRect().topLeft();
        topLeftCorner = mapFromItem(item,topLeftCorner);
        center = mapFromItem(item, center);

        QLineF posCenterLine(center,event->pos());
        QLineF centerCornerLine(center, topLeftCorner);
        *position = posCenterLine.angleTo(centerCornerLine) / 360;

        redraw();
    }
}

void GraphicArrow::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    QPointF pos = event->pos();

    if(QLineF(findSourcePoint(), pos).length() < 20) {
        m_movingSource = true;
    }else if(QLineF(findDestPoint(), pos).length() < 20) {
        m_movingDestination = true;
    }else{
        m_movingSource = false;
        m_movingDestination = false;
    }
}

void GraphicArrow::mouseReleaseEvent(QGraphicsSceneMouseEvent *) {
    m_movingDestination = false;
    m_movingSource = false;
}

// ACCESSEURS ET MUTATEURS
GraphicObject* GraphicArrow::source() const {
    return m_source;
}

GraphicObject *GraphicArrow::destination() const {
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
