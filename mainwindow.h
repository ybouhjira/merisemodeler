#ifndef MAINWINDOW_H
#define MAINWINDOW_H

class ModelUi;

//Qt
#include <QMainWindow>
#include <QVector>
class QTabWidget;


/**
 * @brief The MainWindow class
 */

class MainWindow : public QMainWindow
{
    Q_OBJECT

// METHODS
public:
    /**
     * @brief Returns the unique MainWindow instance
     */
    static MainWindow* getInstance();

    /**
     * @brief Returns the tabWidget that is the central widget of this
     * mainWindow
     */
    QTabWidget* tabWidget() const;

public slots:

    /**
     * @brief creates a new McdUi and adds it to the tabWidget
     */
    void createMcdUi();

    /**
     * @brief Shows the about dialog
     */
    void showAboutDialog();


private:
    /**
     * @brief This constructor is private you should use getInstance method
     */
    MainWindow();

// ATTRIBUTS
private:
    // Singelton pattern
    static MainWindow *instance;

    QVector<ModelUi*> m_modelUis;

    QMenuBar *m_menuBar;
    QMenu
        *m_fileMenu,
        *m_newFileMenu,
        *m_helpMenu;
    QAction
        *m_aboutAction,
        *m_newMcdAction,
        *m_quitAction;
    QTabWidget *m_tabWidget;
};

#endif // MAINWINDOW_H
