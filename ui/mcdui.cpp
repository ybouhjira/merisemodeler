#include "mcdui.h"
#include "mainwindow.h"

#include "logic/entity.h"

#include "model/mcdmodel.h"
#include "model/modelview.h"
#include "model/mcdcontroller.h"

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
#include <QUndoStack>
#include <QGraphicsScene>
#include <QActionGroup>

using namespace Ui;

McdUi* McdUi::m_instance = nullptr;
McdUi* McdUi::getInstance() {
    if(m_instance == nullptr)
        m_instance = new McdUi(MainWindow::getInstance());
    return m_instance;
}

McdUi::McdUi(QWidget *parent)
    : ModelUi(parent)
    // MVC
    , m_model(nullptr)
    , m_scene(new QGraphicsScene)
    , m_controller(new Model::McdController(m_model, m_scene))
    // Actions
    , m_actionGroup(new QActionGroup(this))
    , m_moveAction(new QAction(QIcon(":/cursor"), tr("Move"), m_actionGroup))
    , m_removeAction(new QAction(QIcon(":/erease"), tr("Remove"), m_actionGroup))
    , m_entityAction(new QAction(QIcon(":/entity"), tr("Entity"), m_actionGroup))
    , m_assocAction(new QAction(QIcon(":/assoc"), tr("Association"), m_actionGroup))
    , m_inheritAction(new QAction(QIcon(":/inherit"), tr("Inheritance"), m_actionGroup))
    // EditWidgets
    , m_entityWidget(new EntityEditWidget)
    , m_associationWidget(new AssociationEditWidget)
    , m_itemEditDock(new QDockWidget(tr("Item editing")))
{
    // Barre d'outils
    m_toolBar->addActions(m_actionGroup->actions().mid(0,2));
    m_toolBar->addSeparator();
    m_toolBar->addActions(m_actionGroup->actions().mid(2));
    for(QAction* action : m_actionGroup->actions())
        action->setCheckable(true);

    // DockWidget
    addDockWidget(Qt::BottomDockWidgetArea, m_itemEditDock);
    m_itemEditDock->setWidget(m_entityWidget);

    // Activation de la selection
    m_graphicsView->setDragMode(QGraphicsView::RubberBandDrag);
    m_graphicsView->setInteractive(true);

    // Connections
    // Bouttons de la barre d'outils
    connect(m_moveAction, SIGNAL(triggered()),
            this, SLOT(setMoveClickAction()) );
    connect(m_removeAction, SIGNAL(triggered()),
            this, SLOT(setRemoveClickAction()) );
    connect(m_entityAction, SIGNAL(triggered()),
            this, SLOT(setAddEntityClickAction()) );
    connect(m_assocAction, SIGNAL(triggered()),
            this, SLOT(setAddAssociationClickAction()) );
    connect(m_inheritAction, SIGNAL(triggered()),
            this, SLOT(setInheritencClickAction()) );

    // Mise à jour auto de la vues
    auto updateFunc = [=](){
        m_graphicsView->viewport()->update();
    };
    connect(m_entityWidget, &ItemEditWidget::itemEdited, updateFunc);
    connect(m_associationWidget, &ItemEditWidget::itemEdited, updateFunc);

    // connection de la vue avec le controlleur
    connect(m_graphicsView, SIGNAL(clicked(qreal,qreal)),
            m_controller, SLOT(viewClicked(qreal, qreal)));

}

void McdUi::setModel(Model::McdModel *mcd, QGraphicsScene* scene) {
    // Deconnections de l'ancienne McdGraphicsScene
    if(m_model != nullptr && m_scene != nullptr) {
        disconnect(m_scene, &QGraphicsScene::selectionChanged,
                   this, &McdUi::sceneSelectionChanged );
    }

    m_model = mcd ;
    m_scene = scene;
    m_controller->setModel(mcd);
    m_controller->setScene(scene);
    m_graphicsView->setScene(scene);

    // Connections
    connect(m_scene, &QGraphicsScene::selectionChanged,
            this, &McdUi::sceneSelectionChanged );

    emit modelChanged(mcd);
}

Model::McdModel* McdUi::model() const {
    return m_model ;
}

void McdUi::setMoveClickAction() const {
    m_controller->setClickAction(Model::McdController::Remove);
}

void McdUi::setRemoveClickAction() const {
    m_controller->setClickAction(Model::McdController::Select);
}

void McdUi::setAddEntityClickAction() const {
    m_controller->setClickAction(Model::McdController::AddEntity);
}

void McdUi::setAddAssociationClickAction() const {
    m_controller->setClickAction(Model::McdController::AddAssociation);
}

void McdUi::setInheritencClickAction() const {
    m_controller->setClickAction(Model::McdController::Inheritence);
}

void McdUi::sceneSelectionChanged() {
    QList<QGraphicsItem*> items = m_scene->selectedItems();

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
