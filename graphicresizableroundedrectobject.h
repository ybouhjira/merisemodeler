#ifndef GRAPHICRESIZABLEROUNDEDRECTOBJECT_H
#define GRAPHICRESIZABLEROUNDEDRECTOBJECT_H

#include "graphicroundedrectobject.h"

/**
 * @brief La classe GraphicResizableRoundedRectObject reimplement des méthodes
 * de QGraphicsItem pour permettre le redimensionnement et deplacement des
 * element avec la souris
 */
class GraphicResizableRoundedRectObject : public GraphicRoundedRectObject
{
    // TYPES
private:
    /**
     * @brief Type d'interactions qui l'utilisateur peut avoir avec
     * un element graphique
     */
    enum InteractionMode {
        ResizeLeft,
        ResizeRight,
        ResizeTop,
        ResizeBottom,
        Move,
        None
    };

    // METHODES
public:
    /**
     * @brief Constructeur
     * @param x Abssice
     * @param y Ordonnée
     * @param width Largeur
     * @param height Hauteur
     * @param radius Rayon
     * @param parent Parent
     */
    GraphicResizableRoundedRectObject(
            qreal x,
            qreal y,
            qreal width,
            qreal height,
            qreal radius = 0,
            QGraphicsItem* parent = nullptr);

    /**
     * @reimp
     */
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    /**
     * @reimp
     */
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

    /**
     * @reimp
     */
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

    /**
     * @reimp
     */
    void hoverMoveEvent(QGraphicsSceneHoverEvent *event);

    /**
     * @brief hoverLeaveEvent
     * @param event
     */
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
    // ATTRIBUTS
private:
    static const qreal PADDING ;

    /**
     * @brief Type d'interaction utilisateur actuel
     */
    InteractionMode m_mode;

    /**
     * @brief Le point par lequel l'utilisateur déplace l'element
     */
    QPointF m_grabingPoint;

};

#endif // GRAPHICRESIZABLEROUNDEDRECTOBJECT_H
