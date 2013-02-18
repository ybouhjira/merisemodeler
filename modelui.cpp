#include "modelui.h"

// Qt
#include <QGraphicsView>
#include <QToolBar>

ModelUi::ModelUi(QWidget *parent) :
    QMainWindow(parent)
  , m_graphicsView(new QGraphicsView)
  , m_toolBar(new QToolBar("Barre d'outils"))
{
    setCentralWidget(m_graphicsView);
    addToolBar(Qt::LeftToolBarArea, m_toolBar);
}
