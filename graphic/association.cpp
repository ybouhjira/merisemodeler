#include "association.h"
#include "entity.h"
#include "arrow.h"
#include "cardinalityarrow.h"
#include "logic/association.h"
#include "logic/entity.h"


// Qt
#include <QPainter>
#include <QGraphicsScene>

using namespace Graphic;

Association::Association (
        Logic::Association *association,
        qreal x,
        qreal y,
        qreal width,
        qreal height,
        qreal radius,
        QGraphicsItem* parent
        )
    : ResizableRoundedRectObject(x, y, width, height, radius, parent)
    , m_association(association)
    , m_arrows(new CardinalityArrow(
                   association->links().first->min(),
                   association->links().first->max(),
                   this,
                   association->entity1()->graphicObject(),
                   0.5,
                   0.5,
                   this),
               new CardinalityArrow(
                   association->links().second->min(),
                   association->links().second->max(),
                   this,
                   association->entity2()->graphicObject(),
                   0.5,
                   0.5,
                   this)
               )
{
    association->setGraphicObject(this);

    qreal xEnt1 = association->entity1()->graphicObject()->x() ;
    qreal xEnt2 = association->entity2()->graphicObject()->x() ;

    m_arrows.first->setPosOnDest((this->x() > xEnt1)? 0.35 : 0.85);
    m_arrows.second->setPosOnDest((this->x() > xEnt2)? 0.35 : 0.85);

    m_arrows.first->setPosOnSrc((this->x() > xEnt1)? 0.97 : 0.53);
    m_arrows.second->setPosOnSrc((this->x() > xEnt2)? 0.97 : 0.53);
}

void Association::paint(
        QPainter *painter,
        const QStyleOptionGraphicsItem *option,
        QWidget *widget)
{
    RoundedRectObject::paint(painter, option, widget);

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
    if(!m_association->properties().empty()) {
        qreal lineY = fontHeight + 2 * padding + descent;
        painter->drawLine(0, lineY, width(), lineY);

        // Ecrire les entité
        QList<Logic::Property*> properties = m_association->properties();
        for(int i=0, size=properties.size(); i<size; i++) {
            qreal pHeight = lineY + (padding + fontHeight)*(i + 1);
            painter->drawText(padding, pHeight, properties[i]->name());
        }
    }
}
