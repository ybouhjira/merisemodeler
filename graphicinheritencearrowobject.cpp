#include "graphicinheritencearrowobject.h"
#include "graphicstyle.h"
// Qt
#include <QPainter>

// std
#include <cmath>

GraphicInheritenceArrowObject::GraphicInheritenceArrowObject(
        GraphicObject *source,
        GraphicObject *destination,
        qreal positionOnSource,
        qreal positionOnDestination)
    : GraphicArrow(source, destination, positionOnSource, positionOnDestination)
{
}

void GraphicInheritenceArrowObject::paint
(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    GraphicArrow::paint(painter, option, widget);
    painter->setBrush(style()->brush());

    // Point de destination
    QPointF dest  = findDestPoint();
    // Line entre source et destination
    QLineF line(dest, findSrcPoint());

    // Trouver l'angle entre la ligne et ox
    qreal angle = acos(line.dx() / line.length());
    if (line.dy() >= 0)
            angle = (M_PI * 2) - angle;
    qreal arrowSize = 20;

    // Construire le triangle
    QPointF p1 = dest + QPointF(sin(angle + M_PI / 3) * arrowSize,
                                    cos(angle + M_PI / 3) * arrowSize);
    QPointF p2 = dest + QPointF(sin(angle + M_PI - M_PI / 3) * arrowSize,
                                    cos(angle + M_PI - M_PI / 3) * arrowSize);

    QPolygonF triangle({dest, p1, p2});
    painter->drawPolygon(triangle);
}


QRectF GraphicInheritenceArrowObject::boundingRect() const{
    QRectF rect = GraphicArrow::boundingRect();
    rect.setX(rect.x() - 20);
    rect.setY(rect.y() - 20);
    rect.setHeight(rect.height() + 20);
    rect.setWidth(rect.width() + 20);
    return rect;
}
