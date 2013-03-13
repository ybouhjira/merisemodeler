#ifndef GRAPHICENHERITENCEARROWOBJECT_H
#define GRAPHICENHERITENCEARROWOBJECT_H

#include "graphicarrow.h"

/**
 * @brief GraphicEnheritenceArrowObject est la fléche qui relie deux entité
 * ayant une relation d'héritage
 */
class GraphicInheritenceArrowObject : public GraphicArrow
{
public:
    /**
     * @brief Constructeur
     * @param source Entité fille
     * @param destination Entité mére
     * @param positionOnSource Position de connection avec la source
     * @param positionOnDestination Position de connection avec la destination
     */
    GraphicInheritenceArrowObject(
            GraphicObject *source,
            GraphicObject *destination,
            qreal positionOnSource = 0.25,
            qreal positionOnDestination = 0.75
            );

    /**
     * @reimp
     */
    QRectF boundingRect() const;

protected:
    /**
     * @reimp
     */
    void paint(
            QPainter *painter,
            const QStyleOptionGraphicsItem *option,
            QWidget *widget
            );

};

#endif // GRAPHICENHERITENCEARROWOBJECT_H
