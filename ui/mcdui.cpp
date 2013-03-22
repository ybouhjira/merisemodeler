#include "mcdui.h"
#include "mainwindow.h"

#include "logic/entity.h"

#include "model/mcdmodel.h"
#include "model/mcdscene.h"

#include "graphic/entity.h"
#include "graphic/association.h"

#include "itemeditors/entityeditwidget.h"
#include "itemeditors/associationeditwidget.h"

// Qt
#include <QToolBar>
#include <QAction>
#include <QSignalMapper>
#include <QGraphicsView>
#include <QDockWidget>

using namespace Ui;

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
    , m_associationWidget(new AssociationEditWidget)
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

    auto updateFunc = [=](){
        m_graphicsView->viewport()->update();
    };
    connect(m_entityWidget, &ItemEditWidget::itemEdited, updateFunc);
    connect(m_associationWidget, &ItemEditWidget::itemEdited, updateFunc);

}

void McdUi::setModel(Model::McdModel *mcd) {
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

Model::McdModel* McdUi::model() const {
    return m_model ;
}

void McdUi::setAddEntityModeOnScene() const {
    m_model->scene()->setMode(Model::McdScene::AddEntity);
}

void McdUi::setAddAssocModeOnScene() const {
    m_model->scene()->setMode(Model::McdScene::AddAssociation);
}

void McdUi::setInheritenceModeOnScene() const {
    m_model->scene()->setMode(Model::McdScene::Inheritence);
}

void McdUi::sceneSelectionChanged() {
    QList<QGraphicsItem*> items = m_model->scene()->selectedItems();

    if(!items.empty()) {
        for(QGraphicsItem* item : items) {
            // Tester si c'est une entité
            auto gEntity = dynamic_cast<Graphic::Entity*>(item);
            if(gEntity != nullptr) {
                m_itemEditDock->setWidget(m_entityWidget);
                m_entityWidget->setEntity(gEntity->entity());
            }

            // Tester si c'est une association
            auto gAssoc = dynamic_cast<Graphic::Association*>(item);
            if(gAssoc != nullptr) {
                m_itemEditDock->setWidget(m_associationWidget);
                m_associationWidget->setAssociation(gAssoc->association());
            }
        }
    }
}
