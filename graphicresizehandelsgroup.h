#ifndef GRAPHICRESIZEHANDELSGROUP_H
#define GRAPHICRESIZEHANDELSGROUP_H

#include "graphicroundedrectobject.h"
class GraphicResizeHandel;

/**
 * @brief GraphicResizeHandelsGroup représente un ensemble d'élements de type
 * GraphicResizeHandel qui sert à redimensioner un element
 */
class GraphicResizeHandelsGroup : public GraphicRoundedRectObject
{
    Q_OBJECT
    // METHODES
public:
    /**
     * @brief Constructeur
     * @param parent Element parent
     */
    GraphicResizeHandelsGroup(GraphicRoundedRectObject *parent);

    /**
     * @reimp
     */
    void paint(QPainter *,
               const QStyleOptionGraphicsItem *,
               QWidget *) final override;
    
private slots:
    void topMoved();
    
    // ATTRIBUTS
private:
    /**
     * @brief Controleur de haut
     */
    GraphicResizeHandel* m_top;

    /**
     * @brief Controleur de bas
     */
    GraphicResizeHandel* m_bottom;

    /**
     * @brief Controleur de gauche
     */
    GraphicResizeHandel* m_left;

    /**
     * @brief Controleur de droite
     */
    GraphicResizeHandel* m_right;

    /**
     * @brief Controleur de haut gauche
     */
    GraphicResizeHandel* m_topLeft;

    /**
     * @brief Controleur de haut droite
     */
    GraphicResizeHandel* m_topRight;

    /**
     * @brief Controleur de bas gauche
     */
    GraphicResizeHandel* m_bottomLeft;

    /**
     * @brief Controleur de bas droite
     */
    GraphicResizeHandel* m_bottomRight;
};

#endif // GRAPHICRESIZEHANDELSGROUP_H
