#ifndef GRAPHICENTITY_H
#define GRAPHICENTITY_H

#include "graphicresizableroundedrectobject.h"
class Entity;
class GraphicResizeHandelsGroup;

// Qt
class QCursor;

/**
 * @brief Representation graphique d'une entité
 */
class GraphicEntity : public GraphicResizableRoundedRectObject
{
    // METHODES
public:
    /**
     * @brief Constructeur
     * @param entity L'entité representée
     * @param x Abssice
     * @param y Ordonnée
     * @param width Largeur
     * @param height Hauteur
     * @param parent Element parent
     */
    GraphicEntity(
            Entity *entity,
            qreal x = 0,
            qreal y = 0,
            qreal width = DEFAULT_WIDTH,
            qreal height = DEFAULT_HEIGHT,
            QGraphicsItem *parent = nullptr
            );

    // Methodes reimplementés
    /**
     * @reimp
     */
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;

    // Accesseurs et mutateurs
    /**
     * @brief Accesseur
     * @param entity Entité à representer
     */
    void setEntity(Entity* entity) ;

    /**
     * @brief Mutateur
     * @return L'entité representé
     */
    Entity* entity() const ;

    // ATTRIBUTS
private :

    bool m_resizing = false;

    // static
    /**
     * @brief Largeur par default
     */
    static const int DEFAULT_WIDTH = 100;
    /**
     * @brief Hauteur par default
     */
    static const int DEFAULT_HEIGHT = 100;

    // non static
    /**
     * @brief Entité representée par cet element
     */
    Entity *m_entity;

    //GraphicResizeHandelsGroup *m_handels;
};

#endif // GRAPHICENTITY_H
