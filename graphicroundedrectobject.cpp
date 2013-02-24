#include "graphicroundedrectobject.h"
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
(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget*) {
    painter->drawRoundedRect(x(), y(),m_width, m_height, m_radius, m_radius );

}

QRectF GraphicRoundedRectObject::boundingRect() const {
    return QRectF(x(), y(), m_width, m_height);
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
