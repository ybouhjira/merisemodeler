#include "graphiccardinalityarrow.h"
#include "graphiccardinaltytextitem.h"

// Qt
#include <QGraphicsSimpleTextItem>
#include <QPen>

GraphicCardinalityArrow::GraphicCardinalityArrow(
        AssociationLink::Cardinality min,
        AssociationLink::Cardinality max,
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

void GraphicCardinalityArrow::setMin(AssociationLink::Cardinality min) {
    m_min = min;
}

void GraphicCardinalityArrow::setMax(AssociationLink::Cardinality max) {
    m_max = max ;
}

AssociationLink::Cardinality GraphicCardinalityArrow::min() const {
    return m_min ;
}

AssociationLink::Cardinality GraphicCardinalityArrow::max() const {
    return m_max ;
}

void GraphicCardinalityArrow::redraw() {
    GraphicArrow::redraw();
    m_text->updatePosOnDestCoordinates();
}
