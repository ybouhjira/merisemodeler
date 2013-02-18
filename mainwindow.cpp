#include "mainwindow.h"
#include "mcdui.h"

//Qt
#include <QMenuBar>
#include <QTableWidget>
#include <QMessageBox>
#include <QApplication>

// PUBLIC **********************************************************************
void MainWindow::showAboutDialog() {
    QString txt =
            "Youssef Bouhjira <br/>"
            "Mohamed Doulfakar<br/>"
            "2012-2013";
    QMessageBox::about(this,"A propos de MeriseModeler",txt);
}

void MainWindow::createMcdUi() {
    m_modelUis.append(new McdUi);
    tabWidget()->addTab(m_modelUis.last(),QIcon(":/mcd"),"MCD - sans titre");
}

// STATIC
MainWindow* MainWindow::instance = nullptr;
MainWindow* MainWindow::getInstance() {
    if(instance == nullptr)
        instance = new MainWindow();
    return instance;
}

// PRIVATE *********************************************************************
MainWindow::MainWindow()
    : QMainWindow(nullptr)
    , m_menuBar(new QMenuBar(this))
    , m_fileMenu(new QMenu("Fichier"))
    , m_newFileMenu(new QMenu("Nouveau"))
    , m_helpMenu(new QMenu("Aide"))
    , m_aboutAction(new QAction("A propos",this))
    , m_newMcdAction(new QAction(QIcon(":/mcd"),"MCD",this))
    , m_quitAction(new QAction("Quitter",this))
    , m_tabWidget(new QTabWidget)
{
    setWindowTitle("MeriseModeler");
    // MENUS ===================================================================
    setMenuBar(m_menuBar);
    m_menuBar->addMenu(m_fileMenu);
    m_menuBar->addMenu(m_helpMenu);
    // file menu
    m_fileMenu->addMenu(m_newFileMenu)->setIcon(QIcon(":/new"));
    m_newFileMenu->addAction(m_newMcdAction);
    m_fileMenu->addSeparator();
    m_fileMenu->addAction(m_quitAction);
    // help menu
    m_helpMenu->addAction(m_aboutAction);

    // CENTRAL WIGDET ==========================================================
    setCentralWidget(m_tabWidget);
    m_tabWidget->setTabsClosable(true);
    m_tabWidget->setDocumentMode(true);


    // CONNECTIONS =============================================================
    // file menu
    connect(m_newMcdAction, SIGNAL(triggered()), this, SLOT(createMcdUi()));
    connect(m_quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));

    // help menu
    connect(m_aboutAction, SIGNAL(triggered()), this, SLOT(showAboutDialog()));
}

QTabWidget* MainWindow::tabWidget() const {
    return m_tabWidget;
}
