#include "object.h"
#include "style.h"
#include <QPainter>

using namespace Graphic;

Object::Object(QGraphicsItem* parent)
    : QGraphicsObject(parent)
    , m_style(Style::getDefaultStyle())
{
    setFlag(ItemIsSelectable);
}

Object::~Object() {
}

void Object::setStyle(Style *style) {
    disconnect(m_style, SIGNAL(destroyed()), this, SLOT(setDefaultStyle()));
    connect(style, SIGNAL(destroyed()), this, SLOT(setDefaultStyle()));
    m_style = style;
    emit styleChanged(style);
}

void Object::setDefaultStyle() {
    m_style = Style::getDefaultStyle();
}

Style* Object::style() const {
    return m_style;
}

void Object::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) {
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setRenderHint(QPainter::TextAntialiasing);

    if(m_style == nullptr)
        m_style = Graphic::Style::getDefaultStyle();

    painter->setPen(m_style->pen());
    painter->setFont(m_style->font());
    painter->setBrush(m_style->brush());

    // Selection
    if(isSelected())
        painter->setPen(QPen(QBrush(Qt::blue),2, Qt::DashLine));
}
