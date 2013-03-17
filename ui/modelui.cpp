#include "modelui.h"
#include "mainwindow.h"
#include "pdfsceneexporter.h"
#include "svgsceneexporter.h"

// Qt
#include <QGraphicsView>
#include <QToolBar>
#include <QAction>
#include <QMenuBar>
#include <QFileDialog>

using namespace Ui;

ModelUi::ModelUi(QWidget *parent) :
    QMainWindow(parent)
  , m_graphicsView(new QGraphicsView)
  , m_toolBar(new QToolBar(tr("ToolBar")))
  , m_exportAction(new QAction(tr("Export"), this))
{
    setCentralWidget(m_graphicsView);
    addToolBar(Qt::LeftToolBarArea, m_toolBar);

    // Ajout de l'action exporter dans MainWindow
    QMenu* fileMenu = MainWindow::getInstance()->fileMenu();
    QAction* sep = fileMenu->insertSeparator(fileMenu->actions().last());
    fileMenu->insertAction(sep, m_exportAction);
    fileMenu->insertSeparator(m_exportAction);

    // Connections
    connect(m_exportAction, &QAction::triggered,
            this, &ModelUi::showExportDialog);
}

ModelUi::~ModelUi() {
}

void ModelUi::showExportDialog() {
    // Scene
    QGraphicsScene *modelScene = m_graphicsView->scene();
    if(modelScene == nullptr)
        return;

    // Interroger l'utilisateur
    QString selectedFormat;
    QString filename = QFileDialog::getSaveFileName(
                this,
                tr("Export Model"),
                QDir::home().absolutePath(),
                "PDF(*.pdf);;SVG(*.svg)",
                &selectedFormat);

    if(filename.isEmpty())
        return;

    // Exportation du model
    SceneExporter* exporter = nullptr;

    if(selectedFormat == "PDF(*.pdf)")
        exporter = new PdfSceneExporter;
    else if(selectedFormat == "SVG(*.svg)")
        exporter = new SvgSceneExporter;

        exporter->exportScene(modelScene, filename);
    delete exporter;
}
