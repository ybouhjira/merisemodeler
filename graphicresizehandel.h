#ifndef GRAPHICRESIZEHANDEL_H
#define GRAPHICRESIZEHANDEL_H

#include "graphicroundedrectobject.h"
#include <QCursor>

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
     * @param cursor Curseur affiché lorsque le pointeur de souris est sur
     * cet element
     * @param parent Element parent
     */
    GraphicResizeHandel(qreal x = 0,
                        qreal y = 0,
                        QCursor cursor = QCursor(),
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

    // non static
    QCursor m_cursor;

};

#endif // GRAPHICRESIZEHANDEL_H
