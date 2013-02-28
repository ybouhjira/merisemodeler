#ifndef GRAPHICRESIZEHANDEL_H
#define GRAPHICRESIZEHANDEL_H

#include "graphicroundedrectobject.h"

/**
 * @brief Cette class represente les petit carré qui sert à redimensioner
 * les elements graphiques
 */
class GraphicResizeHandel : public GraphicRoundedRectObject
{
    Q_OBJECT
    // METHODES
public:
    /**
     * @brief GraphicResizeHandel
     * @param x Abssicce
     * @param y Ordonée
     * @param parent Element parent
     */
    GraphicResizeHandel(qreal x = 0,
            qreal y = 0,
            QGraphicsItem *parent = nullptr);

    // ATTRIBUTS
private:
    // static
    /**
     * @brief Rayon = 0
     */
    static const qreal RADIUS;

    /**
     * @brief Largeur / Hauteur du carré
     */
    static const qreal SIZE;

};

#endif // GRAPHICRESIZEHANDEL_H
