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
    , m_addEntityAction(new QAction(QIcon(":/entity"),tr("Entity"),this))
    , m_addAssociationAction(new QAction(QIcon(":/assoc"),tr("Association"),this))
    , m_addInheritanceAction(new QAction(QIcon(":/inherit"),tr("Inheritance"),this))
{
    m_toolBar->addAction(m_addEntityAction);
    m_toolBar->addAction(m_addAssociationAction);
    m_toolBar->addSeparator();
    m_toolBar->addAction(m_addInheritanceAction);
}

void McdUi::setModel(McdModel *mcd) {
    m_model = mcd ;
    m_graphicsView->setScene(mcd->scene());
    emit modelChanged(mcd);
}

McdModel* McdUi::model() const {
    return m_model ;
}
