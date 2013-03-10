#include "graphicroundedrectobject.h"
#include "graphicstyle.h"
#include <QPainter>

GraphicRoundedRectObject::GraphicRoundedRectObject(
        qreal x ,
        qreal y ,
        qreal width ,
        qreal height ,
        qreal radius,
        QGraphicsItem *parent
        )
    : GraphicObject(parent)
    , m_radius(radius)
    , m_width(width)
    , m_height(height)
{
    setX(x);
    setY(y);
}

GraphicRoundedRectObject::~GraphicRoundedRectObject() {
}

void GraphicRoundedRectObject::setRadius(qreal radius) {
    m_radius = radius;
}

qreal GraphicRoundedRectObject::radius() const {
    return m_radius;
}

void GraphicRoundedRectObject::paint
(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget* widget) {
    GraphicObject::paint(painter, option, widget);
    painter->setRenderHint(QPainter::Antialiasing);
    painter->drawRoundedRect(0, 0,m_width, m_height, m_radius, m_radius );
}

QRectF GraphicRoundedRectObject::boundingRect() const {
    int penWidth = style()->pen().width() ;
    return QRectF(
                0 - penWidth,
                0 - penWidth,
                m_width + penWidth,
                m_height + penWidth
                );
}

qreal GraphicRoundedRectObject::height() const {
    return m_height;
}

void GraphicRoundedRectObject::setHeight(qreal height) {
    this->m_height = height;
}

qreal GraphicRoundedRectObject::width() const {
    return m_width;
}

void GraphicRoundedRectObject::setWidth(qreal width) {
    this->m_width = width;
}

QPainterPath GraphicRoundedRectObject::shape() const {
    QPainterPath path;
    path.addRoundedRect(0, 0,m_width, m_height, m_radius, m_radius );
    return path;
}
