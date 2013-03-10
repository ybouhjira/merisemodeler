#ifndef GRAPHICARROW_H
#define GRAPHICARROW_H

#include "graphicobject.h"

// Qt
class QGraphicsRectItem;

/**
 * @brief La classe GraphicArrow represente une flèche qui lie deux éléments
 */
class GraphicArrow : public GraphicObject
{
    Q_OBJECT

    // METHODES
public:
    /**
     * @brief Construit une flèche liant source avec destination. pour chaque
     * element on doit indiquer le coté sur lequel sera accroché la flèche
     * et la position en poucentage.
     * @remarks positionOnSource et positionOnDestionation doivent etre compris
     * entre 0 et 1. si ce n'est pas le cas la valeur la plus proche sera prise
     *
     * @todo Connecter avec widthChanged et heightChanged
     */
    GraphicArrow(
            QGraphicsObject *source,
            QGraphicsObject *destination,
            qreal positionOnSource = 0.5,
            qreal positionOnDestination = 0.5,
            QGraphicsItem *parent = 0);

    virtual ~GraphicArrow();

    // Redefinitions
    /**
     * @reimp
     */
    void paint(
            QPainter *painter,
            const QStyleOptionGraphicsItem *option,
            QWidget *widget);

    /**
     * @reimp
     **/
    QRectF boundingRect() const ;

    /**
     * @reimp
     */
    QPainterPath shape() const;

    /**
     * @reimp
     */
    void hoverEnterEvent(QGraphicsSceneHoverEvent *);

    /**
     * @reimp
     */
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

    /**
     * @reimp
     */
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

    /**
     * @reimp
     */
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    
    // Accesseurs et mutateurs
    /**
     * @brief Accesseur
     * @return Source
     */
    QGraphicsObject* source() const;

    /**
     * @brief Accesseur
     * @return Source
     */
    QGraphicsObject* destination() const;

    /**
     * @brief Accesseur
     * @return Position de connexion avec la source
     */
    qreal positionOnSource() const ;

    /**
     * @brief Accesseur
     * @return Position de connexion avec ka destination
     */
    qreal positionOnDestination() const;
    
public slots:
    /**
     * @brief Mutateur
     * @param position Position entre 0 et 1
     */
    void setPositionOnSource(qreal position);

    /**
     * @brief Mutateur
     * @param position Position entre 0 et 1
     */
    void setPositionOnDestination(qreal position);

    /**
     * @brief Redessine la flèche
     */
    void redraw();

private:
    /**
     * @return Le poit sur lequel doit etre connecté la flèche avec la
     * source en coordonées de cet elements
     */
    inline QPointF findSourcePoint() const;

    /**
     * @return Le poit sur lequel doit etre connecté la flèche avec la
     * destination en coordonées de cet elements
     */
    inline QPointF findDestPoint() const;

    // ATTRIBUTS
private:
    /**
     * @brief Element source
     */
    QGraphicsObject *m_source;

    /**
     * @brief Element de destination
     */
    QGraphicsObject *m_destination;

    /**
     * @brief Postion de l'extrimité de la flèche sur la source en pourcentage
     */
    qreal m_positionOnSource;

    /**
     * @brief Postion de l'extrimité de la flèche sur la destination
     * en pourcentage
     */
    qreal m_positionOnDestionation;

    /**
     * @brief Afficher les controleurs
     */
    bool m_displayHandels;

    /**
     * @brief Indique que la flèche est en train d'etre controlée par l'utilisateur
     */
    bool m_movingSource;

    bool m_movingDestination;
};

#endif // GRAPHICARROW_H
