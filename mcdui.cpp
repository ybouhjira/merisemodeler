#include "mcdui.h"
#include "mcdmodel.h"
#include "entity.h"
#include "mainwindow.h"
#include "mcdgraphicsscene.h"

// Qt
#include <QToolBar>
#include <QAction>
#include <QSignalMapper>
#include <QGraphicsView>

McdUi* McdUi::m_instance = nullptr;
McdUi* McdUi::getInstance() {
    if(m_instance == nullptr)
        m_instance = new McdUi(MainWindow::getInstance());
    return m_instance;
}

McdUi::McdUi(QWidget *parent)
    : ModelUi(parent)
    , m_model(new McdModel(this))
    , m_entityAction(new QAction(QIcon(":/entity"),tr("Entity"),this))
    , m_associationAction(new QAction(QIcon(":/assoc"),tr("Association"),this))
    , m_inheritanceAction(new QAction(QIcon(":/inherit"),tr("Inheritance"),this))
{
    m_toolBar->addAction(m_entityAction);
    m_toolBar->addAction(m_associationAction);
    m_toolBar->addSeparator();
    m_toolBar->addAction(m_inheritanceAction);

    // Activation de la selection
    m_graphicsView->setDragMode(QGraphicsView::RubberBandDrag);
    m_graphicsView->setInteractive(true);

    // Connections
    connect(m_entityAction, SIGNAL(triggered()), this, SLOT(addEntity()) );
    connect(m_associationAction, SIGNAL(triggered()),
            this, SLOT(addAssociation()) );
}

void McdUi::setModel(McdModel *mcd) {
    m_model = mcd ;
    m_graphicsView->setScene(mcd->scene());
    emit modelChanged(mcd);
}

McdModel* McdUi::model() const {
    return m_model ;
}

void McdUi::addEntity() const {
    m_model->scene()->setMode(McdGraphicsScene::AddEntity);
}

void McdUi::addAssociation() const {
    m_model->scene()->setMode(McdGraphicsScene::AddAssociation);
}
