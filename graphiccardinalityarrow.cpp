#include "graphiccardinalityarrow.h"
#include "graphiccardinaltytextitem.h"

// Qt
#include <QGraphicsSimpleTextItem>
#include <QPen>

GraphicCardinalityArrow::GraphicCardinalityArrow(
        Logic::Link::Cardinality min,
        Logic::Link::Cardinality max,
        GraphicObject *source,
        GraphicObject *destination,
        qreal positionOnSource,
        qreal positionOnDestination,
        QGraphicsItem *parent) :
    GraphicArrow(source, destination, positionOnSource, positionOnDestination, parent)
  , m_min(min)
  , m_max(max)
  , m_text(new GraphicCardinalityTextItem(this, min, max))
{

}

GraphicCardinalityArrow::~GraphicCardinalityArrow() {
}

void GraphicCardinalityArrow::setMin(Logic::Link::Cardinality min) {
    m_min = min;
}

void GraphicCardinalityArrow::setMax(Logic::Link::Cardinality max) {
    m_max = max ;
}

Logic::Link::Cardinality GraphicCardinalityArrow::min() const {
    return m_min ;
}

Logic::Link::Cardinality GraphicCardinalityArrow::max() const {
    return m_max ;
}

void GraphicCardinalityArrow::redraw() {
    GraphicArrow::redraw();
    m_text->updatePosOnDestCoordinates();
}
