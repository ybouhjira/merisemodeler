#ifndef GRAPHICASSOCIATION_H
#define GRAPHICASSOCIATION_H

#include "logic/namespace.h"
#include "graphicresizableroundedrectobject.h"
class GraphicArrow;
class GraphicEntity;

class GraphicAssociation : public GraphicResizableRoundedRectObject
{
    // METHODES
public:
    // COnstructeur
    GraphicAssociation(Logic::Association *association,
            qreal x = 0,
            qreal y = 0,
            qreal width = DEFAULT_WIDTH,
            qreal height = DEFAULT_HEIGHT,
            qreal radius = RADIUS,
            QGraphicsItem *parent = nullptr);

    // Redefinition
    /**
     * @reimp
     */
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;

    // ATTRIBUTS
private:
    // static
    /**
     * @brief Le rayon du rectangle arrondis
     */
    static qreal const RADIUS;

    /**
     * @brief Largeur par default
     */
    static qreal const DEFAULT_WIDTH;

    /**
     * @brief Hauteur par default
     */
    static qreal const DEFAULT_HEIGHT;

    // non static
    /**
     * @brief L'association representée
     */
    Logic::Association *m_association;

    /**
     * @brief Flèches
     */
    QPair<GraphicArrow*, GraphicArrow*> m_arrows;


};

#endif // GRAPHICASSOCIATION_H
