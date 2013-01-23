#include "MainWindow.h"
//Qt
#include <QMenuBar>
#include <QTableWidget>
#include <QMessageBox>

// PUBLIC **********************************************************************
void MainWindow::showAboutDialog() {
    QString txt =
            "Youssef Bouhjira <br/>"
            "Mohamed Doulfakar<br/>"
            "2012-2013";
    QMessageBox::about(this,"A propos de MeriseModeler",txt);
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
    , m_helpMenu(new QMenu("Aide"))
    , m_aboutAction(new QAction("A propos",this))
    , m_tabWidget(new QTabWidget)
{
    // MENUS ===================================================================
    setMenuBar(m_menuBar);
    m_menuBar->addMenu(m_fileMenu);
    m_menuBar->addMenu(m_helpMenu);
    // help menu
    m_helpMenu->addAction(m_aboutAction);

    // CENTRAL WIGDET ==========================================================
    setCentralWidget(m_tabWidget);

    // CONNECTIONS =============================================================
    connect(m_aboutAction, &QAction::triggered,
            this, &MainWindow::showAboutDialog);
}

QTabWidget* MainWindow::tabWidget() const {
    return m_tabWidget;
}
