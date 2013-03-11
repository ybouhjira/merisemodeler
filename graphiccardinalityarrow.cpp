#include "graphiccardinalityarrow.h"

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
  , m_text(new QGraphicsSimpleTextItem("",this))
{
    // Texte de la cardinalité
    QString text = "";
    switch(min) {
    case AssociationLink::Zero: text += "0"; break;
    case AssociationLink::One: text += "1"; break;
    case AssociationLink::N: text += "n"; break;
    }
    text += ";";
    switch(max) {
    case AssociationLink::Zero: text += "0"; break;
    case AssociationLink::One: text += "1"; break;
    case AssociationLink::N: text += "n"; break;
    }
    m_text->setText(text);
    m_text->setFlag(ItemIsMovable);
    m_text->setPos(findDestPoint());
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
