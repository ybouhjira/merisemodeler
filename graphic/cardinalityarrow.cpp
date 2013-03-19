#include "cardinalityarrow.h"
#include "cardinaltytextitem.h"

// Qt
#include <QGraphicsSimpleTextItem>
#include <QPen>

CardinalityArrow::CardinalityArrow(
        Logic::Link::Cardinality min,
        Logic::Link::Cardinality max,
        Object *source,
        Object *destination,
        qreal positionOnSource,
        qreal positionOnDestination,
        QGraphicsItem *parent) :
    Arrow(source, destination, positionOnSource, positionOnDestination, parent)
  , m_min(min)
  , m_max(max)
  , m_text(new CardinalityTextItem(this, min, max))
{
}

CardinalityArrow::~CardinalityArrow() {
}

void CardinalityArrow::setMin(Logic::Link::Cardinality min) {
    m_min = min;
    m_text->setMin(min);
    m_text->updateText();
}

void CardinalityArrow::setMax(Logic::Link::Cardinality max) {
    m_max = max ;
    m_text->setMax(max);
    m_text->updateText();
}

Logic::Link::Cardinality CardinalityArrow::min() const {
    return m_min ;
}

Logic::Link::Cardinality CardinalityArrow::max() const {
    return m_max ;
}

void CardinalityArrow::redraw() {
    Arrow::redraw();
    m_text->updatePosOnDestCoordinates();
}
