#include "roundedrectobject.h"
#include "style.h"
#include <QPainter>

using namespace Graphic;

RoundedRectObject::RoundedRectObject(
        qreal x ,
        qreal y ,
        qreal width ,
        qreal height ,
        qreal radius,
        QGraphicsItem *parent
        )
    : Object(parent)
    , m_radius(radius)
    , m_width(width)
    , m_height(height)
{
    setX(x);
    setY(y);
}

RoundedRectObject::~RoundedRectObject() {
}

void RoundedRectObject::setRadius(qreal radius) {
    m_radius = radius;
}

qreal RoundedRectObject::radius() const {
    return m_radius;
}

void RoundedRectObject::paint
(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget* widget) {
    Object::paint(painter, option, widget);
    painter->setRenderHint(QPainter::Antialiasing);
    painter->drawRoundedRect(0, 0,m_width, m_height, m_radius, m_radius );
}

QRectF RoundedRectObject::boundingRect() const {
    int penWidth = style()->pen().width() ;
    return QRectF(0 - penWidth, 0 - penWidth, m_width + penWidth, m_height + penWidth);
}

qreal RoundedRectObject::height() const {
    return m_height;
}

void RoundedRectObject::setHeight(qreal height) {
    this->m_height = height;
}

qreal RoundedRectObject::width() const {
    return m_width;
}

void RoundedRectObject::setWidth(qreal width) {
    this->m_width = width;
}

QPainterPath RoundedRectObject::shape() const {
    QPainterPath path;
    path.addRoundedRect(0, 0,m_width, m_height, m_radius, m_radius );
    return path;
}
