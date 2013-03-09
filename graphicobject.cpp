#include "graphicobject.h"
#include "graphicstyle.h"
#include <QPainter>

GraphicObject::GraphicObject(QGraphicsItem* parent)
    : QGraphicsObject(parent)
    , m_style(GraphicStyle::getDefaultStyle())
{
    setFlag(ItemIsSelectable);
}

GraphicObject::~GraphicObject() {
}

void GraphicObject::setStyle(GraphicStyle *style) {
    m_style = style;
    emit styleChanged(style);
}

GraphicStyle* GraphicObject::style() const {
    return m_style;
}

void GraphicObject::paint(QPainter *painter,
                          const QStyleOptionGraphicsItem *,
                          QWidget *) {
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setRenderHint(QPainter::TextAntialiasing);

    painter->setPen(m_style->pen());
    painter->setFont(m_style->font());
    painter->setBrush(m_style->brush());
    if(isSelected()) {
        painter->setBrush(m_style->brush().color().darker());
    }
}
