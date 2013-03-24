#ifndef MCDVIEW_H
#define MCDVIEW_H

#include "namespace.h"
#include <QGraphicsView>

/**
 * @brief McdView est la vue du model MCD
 */
class Model::ModelView : public QGraphicsView
{
    Q_OBJECT
    // METHODES
public:
    /**
     * @brief Constructeur
     * @param parent Widget parent
     */
    explicit ModelView(QWidget *parent = 0);

protected:
    // Rdéfinititions
    void mousePressEvent(QMouseEvent *event);
    
signals:
    /**
     * @brief Vue cliqué
     */
    void clicked(qreal x, qreal y);

};

#endif // MCDVIEW_H
