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
    m_style = style;
    emit styleChanged(style);
}

Style* Object::style() const {
    return m_style;
}

void Object::paint(QPainter *painter,
                          const QStyleOptionGraphicsItem *,
                          QWidget *) {
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setRenderHint(QPainter::TextAntialiasing);

    painter->setPen(m_style->pen());
    painter->setFont(m_style->font());
    painter->setBrush(m_style->brush());

    // Selection
    if(isSelected()) {
        painter->setBrush(m_style->brush().color().darker());
    }
}
