#include "cardinaltytextitem.h"
#include "cardinalityarrow.h"
// Qt
#include <QGraphicsSceneMoveEvent>

CardinalityTextItem::CardinalityTextItem(CardinalityArrow *parentArrow,
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

Logic::Link::Cardinality CardinalityTextItem::min() const {
    return m_min;
}

Logic::Link::Cardinality CardinalityTextItem::max() const {
    return m_max;
}

void CardinalityTextItem::setMin(Logic::Link::Cardinality min) {
    m_min = min;
}

void CardinalityTextItem::setMax(Logic::Link::Cardinality max) {
    m_max = max;
}

void CardinalityTextItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    m_posOnDestPointCoordinates = pos() - m_parentArrow->findDestPoint();
    setPos(mapToParent(event->pos()));
}

void CardinalityTextItem::updateText() {
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

void CardinalityTextItem::updatePosOnDestCoordinates() {
    setPos( m_posOnDestPointCoordinates + m_parentArrow->findDestPoint());
}
