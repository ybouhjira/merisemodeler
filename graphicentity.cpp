#include "graphicentity.h"
#include "entity.h"
#include "graphicresizehandelsgroup.h"

//Qt
#include <QPainter>
#include <QFontMetrics>
#include <QGraphicsSceneMouseEvent>
#include <QCursor>

GraphicEntity::GraphicEntity(
        Entity *entity,
        qreal x,
        qreal y,
        qreal width,
        qreal height,
        QGraphicsItem *parent) :
    GraphicResizableRoundedRectObject(x, y, width, height, 0, parent)
  , m_entity(entity)
{

}

void GraphicEntity::paint
(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    GraphicRoundedRectObject::paint(painter, option, widget);

    // Couper la region déssinée
    painter->setClipRect(boundingRect());

    // Declaration de variables
    QFontMetrics fontMetrics = painter->fontMetrics();
    const qreal padding = 5 ;
    qreal descent = padding + fontMetrics.descent();
    qreal fontHeight = fontMetrics.height();

    // Erire le nom de l'entité
    QString name = m_entity->name() ;
    qreal x = width() / 2 - padding / 2  - fontMetrics.width(name) / 2 ;
    qreal y = padding + fontHeight;
    painter->drawText(x, y, name);

    // Tracer un trait
    qreal lineY = fontHeight + 2 * padding + descent;
    painter->drawLine(0, lineY, width(), lineY);

    // Ecrire les proprietes
    QList<Property*> properties = m_entity->properties();
    for(int i=0, size=properties.size(); i<size; i++) {
        qreal pHeight = lineY + (padding + fontHeight)*(i + 1);
        painter->drawText(padding, pHeight, properties[i]->name());
    }
}

void GraphicEntity::setEntity(Entity *entity) {
    m_entity = entity;
}

Entity* GraphicEntity::entity() const {
    return m_entity;
}


