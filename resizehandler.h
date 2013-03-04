#ifndef RESIZEHANDELER_H
#define RESIZEHANDELER_H

#include <QGraphicsRectItem>

/**
 * @brief La classe ResizeHandeler represente les petits carré qui permettent
 * de redimensionner les elements Graphiques
 */
class ResizeHandler : public QGraphicsRectItem
{
public:
    /**
     * @brief Constructeur
     * @param parent Element parent
     */
    explicit ResizeHandler(QGraphicsItem *parent = 0);
    
    
};

#endif // RESIZEHANDELER_H
