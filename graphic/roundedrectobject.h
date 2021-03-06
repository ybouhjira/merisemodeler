#ifndef GRAPHICROUNDEDRECTOBJECT_H
#define GRAPHICROUNDEDRECTOBJECT_H

#include "namespace.h"
#include "object.h"

/**
 * @brief GraphicRoundedRectObject reimplmente les fonctions paint()
 * et boundingRect() pour representer un rectangle avec des coins arrondis
 */
class Graphic::RoundedRectObject : public Graphic::Object
{
    Q_OBJECT
    // METHODES
public:
    // Constructeurs et destructeurs
    /**
     * @brief Constructeur
     * @param x Abscisse
     * @param y Ordonnée
     * @param width Largeur
     * @param height Hauteur
     * @param parent Element parent
     */
    explicit RoundedRectObject(
            qreal x ,
            qreal y ,
            qreal width ,
            qreal height ,
            qreal radius=0,
            QGraphicsItem *parent = nullptr);

    /**
     * @brief Destructeur
     */
    virtual ~RoundedRectObject();

    // Accesseur et mutateurs
    /**
     * @brief Accesseur
     * @return Rayon
     */
    qreal radius() const;

    /**
     * @brief Mutateur
     * @param radius Rayon
     */
    void setRadius(qreal radius);

    /**
     * @brief Accesseur
     * @return Hauteur
     */
    qreal height() const ;

    /**
     * @brief Mutateur
     * @param Heuteur
     */
    void setHeight(qreal height) ;

    /**
     * @brief Accesseur
     * @return Largeur
     */
    qreal width() const ;

    /**
     * @brief Mutateur
     * @param Largeur
     */
    void setWidth(qreal width) ;

    // Méthodes redéfinies
    /**
     * @reimp
     */
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;

    /**
     * @reimp
     */
    QRectF boundingRect() const override;

    /**
     * @reimp
     **/
    QPainterPath shape() const ;

    //ATTRIBUTS
private:
    /**
     * @brief Rayon
     */
    qreal m_radius;

    /**
     * @brief Largeur
     */
    qreal m_width;

    /**
     * @brief Hauteur
     */
    qreal m_height;
};

#endif // GRAPHICROUNDEDRECTOBJECT_H
