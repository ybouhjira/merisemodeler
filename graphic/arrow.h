#ifndef Arrow_H
#define Arrow_H

#include "namespace.h"
#include "object.h"

// Qt
class QGraphicsRectItem;

/**
 * @brief La classe Arrow represente une flèche qui lie deux éléments
 */
class Graphic::Arrow : public Graphic::Object
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
    Arrow(
            Object *source,
            Object *destination,
            qreal positionOnSource = 0.5,
            qreal positionOnDestination = 0.5,
            QGraphicsItem *parent = 0);

    virtual ~Arrow();

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

    /**
     * @reimp
     */
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *);
    
    // Accesseurs et mutateurs
    /**
     * @brief Accesseur
     * @return Source
     */
    Object* source() const;

    /**
     * @brief Accesseur
     * @return Source
     */
    Object* destination() const;

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
    void setPosOnSrc(qreal position);

    /**
     * @brief Mutateur
     * @param position Position entre 0 et 1
     */
    void setPosOnDest(qreal position);

    /**
     * @brief Redessine la flèche
     */
    virtual void redraw();

    /**
     * @return Le point sur lequel doit etre connecté la flèche avec la
     * source en coordonées de cet elements
     */
    QPointF findSrcPoint() const;

    /**
     * @return Le point sur lequel doit etre connecté la flèche avec la
     * destination en coordonées de cet elements
     */
    QPointF findDestPoint() const;

    // ATTRIBUTS
private:
    // static
    constexpr static const qreal HANDLE_SIZE = 6 ;

    // non static
    /**
     * @brief Element source
     */
    Object *m_source;

    /**
     * @brief Element de destination
     */
    Object *m_destination;

    /**
     * @brief Postion de l'extrimité de la flèche sur la source en pourcentage
     */
    qreal m_posOnSrc;

    /**
     * @brief Postion de l'extrimité de la flèche sur la destination
     * en pourcentage
     */
    qreal m_positionOnDest;

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

#endif // Arrow_H
