#include "mcdui.h"
#include "mcdmodel.h"
#include "entity.h"
#include "mainwindow.h"
#include "mcdgraphicsscene.h"
#include "entityeditwidget.h"
#include "graphicentity.h"
#include "graphicassociation.h"

// Qt
#include <QToolBar>
#include <QAction>
#include <QSignalMapper>
#include <QGraphicsView>
#include <QDockWidget>

McdUi* McdUi::m_instance = nullptr;
McdUi* McdUi::getInstance() {
    if(m_instance == nullptr)
        m_instance = new McdUi(MainWindow::getInstance());
    return m_instance;
}

McdUi::McdUi(QWidget *parent)
    : ModelUi(parent)
    , m_model(nullptr)
    , m_entityAction(new QAction(QIcon(":/entity"),tr("Entity"),this))
    , m_associationAction(new QAction(QIcon(":/assoc"),tr("Association"),this))
    , m_inheritanceAction(new QAction(QIcon(":/inherit"),tr("Inheritance"),this))
    , m_entityWidget(new EntityEditWidget)
    , m_itemEditDock(new QDockWidget(tr("Item editing")))
{
    // Barre d'outils
    m_toolBar->addAction(m_entityAction);
    m_toolBar->addAction(m_associationAction);
    m_toolBar->addSeparator();
    m_toolBar->addAction(m_inheritanceAction);

    // Graphics View
    m_graphicsView->setSceneRect(0,0,2000,2000);
    m_graphicsView->scroll(-1000, -1000);

    // DockWidget
    addDockWidget(Qt::BottomDockWidgetArea, m_itemEditDock);
    m_itemEditDock->setWidget(m_entityWidget);

    // Activation de la selection
    m_graphicsView->setDragMode(QGraphicsView::RubberBandDrag);
    m_graphicsView->setInteractive(true);

    // Connections
    // Bouttons de la barre d'outils
    connect(m_entityAction, SIGNAL(triggered()),
            this, SLOT(setAddEntityModeOnScene()) );
    connect(m_associationAction, SIGNAL(triggered()),
            this, SLOT(setAddAssocModeOnScene()) );
    connect(m_inheritanceAction, SIGNAL(triggered()),
            this, SLOT(setInheritenceModeOnScene()) );

    connect(m_entityWidget, &EntityEditWidget::entityEdited, [=](Entity* ent){
        QGraphicsItem *gEntity = ent->graphicObject();
        m_graphicsView->updateScene({gEntity->boundingRect()});
        m_graphicsView->update();
    });
}

void McdUi::setModel(McdModel *mcd) {
    // Deconnections de l'ancienne McdGraphicsScene
    if(m_model != nullptr && m_model->scene() != nullptr) {
        disconnect(mcd->scene(), &QGraphicsScene::selectionChanged,
                   this, &McdUi::sceneSelectionChanged );
    }

    m_model = mcd ;
    m_graphicsView->setScene(mcd->scene());

    // Connections
    connect(m_model->scene(), &QGraphicsScene::selectionChanged,
            this, &McdUi::sceneSelectionChanged );

    emit modelChanged(mcd);
}

McdModel* McdUi::model() const {
    return m_model ;
}

void McdUi::setAddEntityModeOnScene() const {
    m_model->scene()->setMode(McdGraphicsScene::AddEntity);
}

void McdUi::setAddAssocModeOnScene() const {
    m_model->scene()->setMode(McdGraphicsScene::AddAssociation);
}

void McdUi::setInheritenceModeOnScene() const {
    m_model->scene()->setMode(McdGraphicsScene::Inheritence);
}

void McdUi::sceneSelectionChanged() {
    QList<QGraphicsItem*> items = m_model->scene()->selectedItems();

    if(!items.empty()) {
        for(QGraphicsItem* item : items) {
            // Tester si c'est une entité
            auto gEntity = dynamic_cast<GraphicEntity*>(item);
            if(gEntity != nullptr) {
                m_itemEditDock->setWidget(m_entityWidget);
                m_entityWidget->setEntity(gEntity->entity());
            }
        }
    }
}
