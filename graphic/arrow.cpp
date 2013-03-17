#include "arrow.h"
#include "style.h"

// Qt
#include <QPainter>
#include <QGraphicsItem>
#include <QPainterPath>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QCursor>

using namespace Graphic;
// PRIVATE
QPointF Arrow::findSrcPoint() const {
    QPointF s = m_source->shape().pointAtPercent(m_posOnSrc);
    return mapFromItem(m_source,s) ;
}

QPointF Arrow::findDestPoint() const {
    QPointF d = m_destination->shape().pointAtPercent(m_positionOnDest);
    return mapFromItem(m_destination,d) ;
}

// CONSTRUCTEUR
Arrow::Arrow(
        Object *source,
        Object *destination,
        qreal positionOnSource,
        qreal positionOnDestination,
        QGraphicsItem *parent) :
    Object(parent)
  , m_source(source)
  , m_destination(destination)
  , m_posOnSrc(positionOnSource)
  , m_positionOnDest(positionOnDestination)
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

Arrow::~Arrow() {
}

void Arrow::paint
(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Object::paint(painter, option, widget);
    QPointF s = findSrcPoint();
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

QRectF Arrow::boundingRect() const {
    QPointF s = findSrcPoint() ;
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

QPainterPath Arrow::shape() const {
    QPointF s = findSrcPoint() ;
    QPointF d = findDestPoint() ;

    QPainterPath path(s);
    path.lineTo(d);

    // Pour inclure la largeur du trait
    QPainterPathStroker stroker;
    stroker.setWidth(HANDLE_SIZE / 2);
    return stroker.createStroke(path);
}

// EVENTS
void Arrow::hoverEnterEvent(QGraphicsSceneHoverEvent *event) {
    m_displayHandels = true ;

    if(QLineF(findSrcPoint(), event->pos()).length() < HANDLE_SIZE)
        setCursor(Qt::SizeAllCursor);
    else if(QLineF(findDestPoint(), event->pos()).length() < HANDLE_SIZE)
        setCursor(Qt::SizeAllCursor);
    else
        setCursor(QCursor());

    update(boundingRect());
}

void Arrow::hoverLeaveEvent(QGraphicsSceneHoverEvent *) {
    m_displayHandels = false ;
    update(boundingRect());
}

void Arrow::mouseMoveEvent(QGraphicsSceneMouseEvent *e) {
    if (m_movingSource || m_movingDestination) {
        qreal &pos = m_movingSource? m_posOnSrc : m_positionOnDest;
        Object *item = m_movingSource? m_source : m_destination;

        QPointF center = mapFromItem(item, item->boundingRect().center());
        QPointF corner = mapFromItem(item, item->boundingRect().topLeft());

        qreal angle = QLineF(center,e->pos()).angleTo(QLineF(center, corner));
        pos = angle / 360;

        redraw();
    }
}

void Arrow::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    QPointF pos = event->pos();

    if(QLineF(findSrcPoint(), pos).length() < 20) {
        m_movingSource = true;
    }else if(QLineF(findDestPoint(), pos).length() < 20) {
        m_movingDestination = true;
    }else{
        m_movingSource = false;
        m_movingDestination = false;
    }
}

void Arrow::mouseReleaseEvent(QGraphicsSceneMouseEvent *) {
    m_movingDestination = false;
    m_movingSource = false;
}

// ACCESSEURS ET MUTATEURS
Object* Arrow::source() const {
    return m_source;
}

Object *Arrow::destination() const {
    return m_destination;
}

qreal Arrow::positionOnSource() const {
    return m_posOnSrc;
}

qreal Arrow::positionOnDestination() const {
    return m_positionOnDest;
}

void Arrow::setPosOnSrc(qreal position) {
    m_posOnSrc  = position ;
}

void Arrow::setPosOnDest(qreal position) {
    m_positionOnDest = position;
}

void Arrow::redraw() {
    prepareGeometryChange();
    update(boundingRect());
}
