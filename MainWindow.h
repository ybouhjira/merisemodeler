#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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

    QMenuBar *m_menuBar;
    QMenu
        *m_fileMenu,
        *m_helpMenu;
    QAction *m_aboutAction;
    QTabWidget *m_tabWidget;
};

#endif // MAINWINDOW_H
