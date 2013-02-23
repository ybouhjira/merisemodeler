#ifndef GRAPHICENTITY_H
#define GRAPHICENTITY_H

class Entity;
// Qt
#include <QGraphicsRectItem>

class GraphicEntity : public QGraphicsRectItem
{
    // METHODES
public:
    /**
     * @brief GraphicEntity
     * @param entity entité representée
     * @param parent Element parent
     */
    GraphicEntity(Entity *entity, QGraphicsItem *parent = 0);

    // Methodes reimplementés
    /**
     * @brief redefinition de GraphicsRectItem::paint
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


    friend class TestGraphicEntity;
};

#endif // GRAPHICENTITY_H
