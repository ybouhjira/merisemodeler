#include "graphiccardinaltytextitem.h"
#include "graphiccardinalityarrow.h"
// Qt
#include <QGraphicsSceneMoveEvent>

GraphicCardinalityTextItem::GraphicCardinalityTextItem(
        GraphicCardinalityArrow* parentArrow,
        Logic::Link::Cardinality min,
        Logic::Link::Cardinality max)
    : QGraphicsSimpleTextItem(parentArrow)
    , m_min(min)
    , m_max(max)
    , m_posOnDestPointCoordinates(0,0)
    , m_parentArrow(parentArrow)
{
    updateText();
    updatePosOnDestCoordinates();
}

Logic::Link::Cardinality GraphicCardinalityTextItem::min() const {
    return m_min;
}

Logic::Link::Cardinality GraphicCardinalityTextItem::max() const {
    return m_max;
}

void GraphicCardinalityTextItem::setMin(Logic::Link::Cardinality min) {
    m_min = min;
}

void GraphicCardinalityTextItem::setMax(Logic::Link::Cardinality max) {
    m_max = max;
}

void GraphicCardinalityTextItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    m_posOnDestPointCoordinates = pos() - m_parentArrow->findDestPoint();
    setPos(mapToParent(event->pos()));
}

void GraphicCardinalityTextItem::updateText() {
    // Texte de la cardinalité
    QString text = "";
    switch(m_min) {
    case Logic::Link::Zero: text += "0"; break;
    case Logic::Link::One: text += "1"; break;
    case Logic::Link::N: text += "n"; break;
    }
    text += ";";
    switch(m_max) {
    case Logic::Link::Zero: text += "0"; break;
    case Logic::Link::One: text += "1"; break;
    case Logic::Link::N: text += "n"; break;
    }

    setText(text);
    setFlag(ItemIsMovable);
}

void GraphicCardinalityTextItem::updatePosOnDestCoordinates() {
    setPos( m_posOnDestPointCoordinates + m_parentArrow->findDestPoint());
}
