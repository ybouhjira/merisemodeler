#include "graphicassociation.h"
#include "association.h"
// Qt
#include <QPainter>

qreal const GraphicAssociation::RADIUS = 25;
qreal const GraphicAssociation::DEFAULT_WIDTH = 100;
qreal const GraphicAssociation::DEFAULT_HEIGHT = 100;

GraphicAssociation::GraphicAssociation (
        Association *association,
        qreal x,
        qreal y,
        qreal width,
        qreal height,
        qreal radius,
        QGraphicsItem* parent
        )
    : GraphicRoundedRectObject(x, y, width, height, radius, parent)
    , m_association(association)
{
    setFlag(QGraphicsItem::ItemIsMovable);
}

void GraphicAssociation::paint(
        QPainter *painter,
        const QStyleOptionGraphicsItem *option,
        QWidget *widget)
{
    GraphicRoundedRectObject::paint(painter, option, widget);

    // Couper la region déssinée
    painter->setClipRect(boundingRect());

    // Declaration de variables
    QFontMetrics fontMetrics = painter->fontMetrics();
    const qreal padding = 5 ;
    qreal descent = padding + fontMetrics.descent();
    qreal fontHeight = fontMetrics.height();


    // Erire le nom de l'entité
    QString name = m_association->name() ;
    qreal x = width() / 2 - padding / 2  - fontMetrics.width(name) / 2 ;
    qreal y = padding + fontHeight;
    painter->drawText(x, y, name);

    // Tracer un trait
    qreal lineY = fontHeight + 2 * padding + descent;
    painter->drawLine(0, lineY, width(), lineY);

    // Ecrire les entité
    QList<Property*> properties = m_association->properties();
    for(int i=0, size=properties.size(); i<size; i++) {
        qreal pHeight = lineY + (padding + fontHeight)*(i + 1);
        painter->drawText(padding, pHeight, properties[i]->name());
    }
}
