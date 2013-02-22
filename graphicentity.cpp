#include "graphicentity.h"
#include "entity.h"

GraphicEntity::GraphicEntity(Entity *entity, QGraphicsItem *parent) :
    QGraphicsRectItem(parent)
  , m_entity(entity)
{
    setAcceptHoverEvents(true);
}

void GraphicEntity::paint
(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    QGraphicsRectItem::paint(painter, option, widget);
}

void GraphicEntity::setEntity(Entity *entity) {
    m_entity = entity;
}

Entity* GraphicEntity::entity() const {
    return m_entity;
}
