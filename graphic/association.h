#ifndef GRAPHICASSOCIATION_H
#define GRAPHICASSOCIATION_H

#include "namespace.h"
#include "resizableroundedrectobject.h"
#include "logic/namespace.h"

class Graphic::Association : public Graphic::ResizableRoundedRectObject
{
    // METHODES
public:
    // COnstructeur
    Association(Logic::Association *association,
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

    /**
     * @brief Accesseur
     * @return
     */
    Logic::Association* association() const;

    void setAssociation(Logic::Association* assoc);

    // ATTRIBUTS
private:
    // static
    /**
     * @brief Le rayon du rectangle arrondis
     */
    constexpr static qreal const RADIUS = 25;

    /**
     * @brief Largeur par default
     */
    constexpr static qreal const DEFAULT_WIDTH = 100;

    /**
     * @brief Hauteur par default
     */
    constexpr static qreal const DEFAULT_HEIGHT = 50;

    // non static
    /**
     * @brief L'association representée
     */
    Logic::Association *m_association;

    /**
     * @brief Flèches
     */
    QPair<Graphic::Arrow*, Graphic::Arrow*> m_arrows;


};

#endif // GRAPHICASSOCIATION_H
