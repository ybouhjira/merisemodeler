#include "modelview.h"
#include <QMouseEvent>

using namespace Model;

ModelView::ModelView(QWidget *parent) :
    QGraphicsView(parent)
{
}

void ModelView::mousePressEvent(QMouseEvent *event) {
    QGraphicsView::mousePressEvent(event);
    qreal x = mapToScene(event->pos()).x();
    qreal y = mapToScene(event->pos()).y();
    emit clicked(x, y);
}
