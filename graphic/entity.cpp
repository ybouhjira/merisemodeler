#include "entity.h"
#include "logic/entity.h"
#include "style.h"
#include "logic/property.h"

//Qt
#include <QPainter>
#include <QFontMetrics>
#include <QGraphicsSceneMouseEvent>
#include <QCursor>

using namespace Graphic;

Entity::Entity(
        Logic::Entity *entity,
        qreal x,
        qreal y,
        qreal width,
        qreal height,
        QGraphicsItem *parent) :
    ResizableRoundedRectObject(x, y, width, height, 0, parent)
  , m_entity(entity)
{
    entity->setGraphicObject(this);

    // Connection
    connect(m_entity, &Logic::Item::nameChanged, [=](){ update(boundingRect()); });
}

void Entity::paint
(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    RoundedRectObject::paint(painter, option, widget);

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
    QFont underlined = style()->font();
    underlined.setUnderline(true);

    QList<Logic::Property*> pts = m_entity->properties();
    for(int i=0; i<pts.size(); i++) {
        // sourligner les identifiants
        painter->setFont(pts[i]->isIdentifier()? underlined : style()->font());
        qreal pHeight = lineY + (padding + fontHeight)*(i + 1);
        painter->drawText(padding, pHeight, pts[i]->name());
    }
}

void Entity::setEntity(Logic::Entity *entity) {
    m_entity = entity;
}

Logic::Entity* Entity::entity() const {
    return m_entity;
}


