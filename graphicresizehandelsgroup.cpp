#include "graphicresizehandelsgroup.h"
#include "graphicresizehandel.h"

GraphicResizeHandelsGroup::GraphicResizeHandelsGroup(
        GraphicRoundedRectObject *parent) :
    GraphicRoundedRectObject(0, 0, parent->width(), parent->height(), 0, parent)
{
    qreal w = parent->width() ;
    qreal h = parent->height() ;

    // Mettre les handel dans leur place
    m_top = new GraphicResizeHandel(w/2, 0, Qt::SizeVerCursor, this);
    m_bottom = new GraphicResizeHandel(w/2, h, Qt::SizeVerCursor, this);
    m_left = new GraphicResizeHandel(0, h/2, Qt::SizeHorCursor, this);
    m_right = new GraphicResizeHandel(w, h/2, Qt::SizeHorCursor, this);
    m_topLeft = new GraphicResizeHandel(0, 0, Qt::SizeBDiagCursor, this);
    m_topRight = new GraphicResizeHandel(w, 0, Qt::SizeFDiagCursor, this);
    m_bottomLeft = new GraphicResizeHandel(0, h, Qt::SizeFDiagCursor, this);
    m_bottomRight = new GraphicResizeHandel(w, h, Qt::SizeBDiagCursor, this);
}


void GraphicResizeHandelsGroup::paint(QPainter *,
                                      const QStyleOptionGraphicsItem *,
                                      QWidget *) {

}
