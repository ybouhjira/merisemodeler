#include "mainwindow.h"
#include "mcdui.h"
#include "modelstabwidget.h"
#include "mcdmodel.h"

//Qt
#include <QMenuBar>
#include <QTableWidget>
#include <QMessageBox>
#include <QApplication>
#include <QTabBar>
#include <QVBoxLayout>
#include <QStatusBar>

void MainWindow::showAboutDialog() {
    QString txt =
            "Youssef Bouhjira <br/>"
            "Mohamed Doulfakar<br/>"
            "2012-2013";
    QMessageBox::about(this,"A propos de MeriseModeler",txt);
}

MainWindow* MainWindow::instance = nullptr;
MainWindow* MainWindow::getInstance() {
    if(instance == nullptr)
        instance = new MainWindow();
    return instance;
}

MainWindow::MainWindow()
    : QMainWindow(nullptr)
    , m_tabWidget(new ModelsTabWidget(this))
    , m_fileMenu(new QMenu(tr("File")))
    , m_newFileMenu(new QMenu(tr("New")))
    , m_helpMenu(new QMenu(tr("Help")))
    , m_aboutAction(new QAction(tr("About"),this))
    , m_newMcdAction(new QAction(QIcon(":/mcd"),"MCD",this))
    , m_quitAction(new QAction(tr("Quit"),this))
{
    setWindowTitle("MeriseModeler");

    // MENUS
    setMenuBar(new QMenuBar(this));
    menuBar()->addMenu(m_fileMenu);
    menuBar()->addMenu(m_helpMenu);
    // file menu
    m_fileMenu->addMenu(m_newFileMenu)->setIcon(QIcon(":/new"));
    m_newFileMenu->addAction(m_newMcdAction);
    m_fileMenu->addSeparator();
    m_fileMenu->addAction(m_quitAction);
    // help menu
    m_helpMenu->addAction(m_aboutAction);

    // CENTRAL WIGDET
    setCentralWidget(m_tabWidget);

    // CONNECTIONS
    // file menu
    connect(m_quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));
    // -> new
    connect(m_newMcdAction, SIGNAL(triggered()), this, SLOT(createNewMcd()));

    // help menu
    connect(m_aboutAction, SIGNAL(triggered()), this, SLOT(showAboutDialog()));
}

void MainWindow::createNewMcd() const{
    m_tabWidget->addModel(tr("unamed"), new McdModel);
}

QMenu* MainWindow::fileMenu() {
    return m_fileMenu;
}
