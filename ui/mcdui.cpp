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

#include "exporter/exporterfactory.h"
#include "exporter/graphicssceneexporter.h"

// Qt
#include <QToolBar>
#include <QAction>
#include <QSignalMapper>
#include <QGraphicsView>
#include <QDockWidget>
#include <QUndoStack>
#include <QGraphicsScene>
#include <QActionGroup>
#include <QFileDialog>
#include <QMenu>
#include <QUndoView>

using namespace Ui;

McdUi* McdUi::m_instance = nullptr;
McdUi* McdUi::getInstance() {
    if(m_instance == nullptr)
        m_instance = new McdUi(MainWindow::getInstance());
    return m_instance;
}

McdUi::McdUi(QWidget *parent)
    : QMainWindow(parent)
    // MVC
    , m_model(nullptr)
    , m_scene(new QGraphicsScene)
    , m_controller(new Model::McdController(m_model, m_scene))
    // Actions
    , m_actionGroup(new QActionGroup(this))
    , m_undoAction(new QAction(QIcon(":/undo"), tr("Undo"), m_actionGroup))
    , m_redoAction(new QAction(QIcon(":/redo"), tr("Redo"), m_actionGroup))
    , m_moveAction(new QAction(QIcon(":/cursor"), tr("Move"), m_actionGroup))
    , m_removeAction(new QAction(QIcon(":/erease"), tr("Remove"), m_actionGroup))
    , m_entityAction(new QAction(QIcon(":/entity"), tr("Entity"), m_actionGroup))
    , m_assocAction(new QAction(QIcon(":/assoc"), tr("Association"), m_actionGroup))
    , m_inheritAction(new QAction(QIcon(":/inherit"), tr("Inheritance"), m_actionGroup))
    // EditWidgets
    , m_entityWidget(new EntityEditWidget)
    , m_associationWidget(new AssociationEditWidget)
    , m_itemEditDock(new QDockWidget(tr("Item editing")))
    // ---
    , m_graphicsView(new Model::ModelView)
    , m_toolBar(new QToolBar("Barre d'outils"))
    , m_exportAction(new QAction(tr("Export"), this))
    , m_undoView(new QUndoView)
{
    setCentralWidget(m_graphicsView);
    addToolBar(Qt::LeftToolBarArea, m_toolBar);
    m_toolBar->setMovable(false);
    // Barre d'outils
    m_toolBar->addActions(m_actionGroup->actions().mid(0,2));
    m_toolBar->addSeparator();
    m_toolBar->addActions(m_actionGroup->actions().mid(2,5));
    m_toolBar->addSeparator();
    m_toolBar->addActions(m_actionGroup->actions().mid(5));
    for(int i=2; i<m_actionGroup->actions().size(); i++)
        m_actionGroup->actions()[i]->setCheckable(true);

    // DockWidget
    addDockWidget(Qt::BottomDockWidgetArea, m_itemEditDock);
    m_itemEditDock->setWidget(m_entityWidget);

    // Activation de la selection
    m_graphicsView->setDragMode(QGraphicsView::RubberBandDrag);
    m_graphicsView->setInteractive(true);

    // Ajout de l'action exporter dans MainWindow
    QMenu* fileMenu = MainWindow::getInstance()->fileMenu();
    QAction* sep = fileMenu->insertSeparator(fileMenu->actions().last());
    fileMenu->insertAction(sep, m_exportAction);
    fileMenu->insertSeparator(m_exportAction);

    // Undo view
    auto undoDock = new QDockWidget(tr("History"), this);
    addDockWidget(Qt::RightDockWidgetArea, undoDock);
    undoDock->setWidget(m_undoView);
    m_undoView->setStack(m_controller->stack());

    // CONNETIONS
    // export
    connect(m_exportAction, &QAction::triggered, this, &McdUi::showExportDialog);

    // Bouttons de la barre d'outils
    connect(m_moveAction, SIGNAL(triggered()), this, SLOT(setMoveClickAction()) );
    connect(m_removeAction, SIGNAL(triggered()), this, SLOT(setRemoveClickAction()) );
    connect(m_entityAction, SIGNAL(triggered()), this, SLOT(setAddEntityClickAction()) );
    connect(m_assocAction, SIGNAL(triggered()), this, SLOT(setAddAssociationClickAction()) );
    connect(m_inheritAction, SIGNAL(triggered()), this, SLOT(setInheritencClickAction()) );

    // Mise à jour auto de la vues
    auto updateFunc = [=](){ m_graphicsView->viewport()->update(); };
    connect(m_entityWidget, &ItemEditWidget::itemEdited, updateFunc);
    connect(m_associationWidget, &ItemEditWidget::itemEdited, updateFunc);

    // connection de la vue avec le controlleur
    connect(m_graphicsView, SIGNAL(clicked(qreal,qreal)), m_controller, SLOT(viewClicked(qreal, qreal)));

    // undo & redo
    connect(m_undoAction, SIGNAL(triggered()), m_controller, SLOT(undo()));
    connect(m_redoAction, SIGNAL(triggered()), m_controller, SLOT(redo()));
}

void McdUi::setModel(Model::McdModel *mcd, QGraphicsScene* scene) {
    // Deconnections de l'ancienne McdGraphicsScene
    if(m_model != nullptr && m_scene != nullptr)
        disconnect(m_scene, SIGNAL(selectionChanged()), this, SLOT(sceneSelectionChanged()) );

    m_model = mcd ;
    m_scene = scene;
    m_controller->setModel(mcd);
    m_controller->setScene(scene);
    m_graphicsView->setScene(scene);

    // Connections
    connect(m_scene, SIGNAL(selectionChanged()), this, SLOT(sceneSelectionChanged()));
    emit modelChanged(mcd);
}

Model::McdModel* McdUi::model() const {
    return m_model ;
}

void McdUi::setMoveClickAction() const {
    m_controller->setClickAction(Model::McdController::Select);
}

void McdUi::setRemoveClickAction() const {
    m_controller->setClickAction(Model::McdController::Remove);
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

void McdUi::showExportDialog() {
    QString format;
    QString path = QFileDialog::getSaveFileName(this, tr("Export Model"), "", "PDF(*.pdf);;SVG(*.svg)", &format);
    if(path.isEmpty())
        return;
    Exporter::SceneExporter* exporter = ExporterFactory::create(format);
    exporter->exportScene(m_scene, path);
    delete exporter;
}
