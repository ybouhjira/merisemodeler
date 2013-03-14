#ifndef MAINWINDOW_H
#define MAINWINDOW_H

class ModelUi;
class ModelsTabWidget;

//Qt
#include <QMainWindow>
#include <QVector>
class QTabBar;

/**
 * @brief La classe de la fenetre principale
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

// METHODES
public:
    /**
     * @brief Retourne l'instance unique de cette classe
     */
    static MainWindow* getInstance();

    /**
     * @return Le menu fichier
     */
    QMenu* fileMenu() ;

public slots:
    /**
     * @brief Affiche le message a propos
     */
    void showAboutDialog();

    /**
     * @brief Crée un nouveau MCD
     */
    void createNewMcd() const;

private:
    /**
     * @brief This constructor is private you should use getInstance method
     */
    MainWindow();

// ATTRIBUTS
private:
    // static
    /**
     * @brief Singelton
     */
    static MainWindow *instance;

    // non static
    ModelsTabWidget *m_tabWidget;

    /**
     * @brief Menu fichier
     */
    QMenu *m_fileMenu;

    /**
     * @brief Menu Fichier > Nouveau
     */
    QMenu *m_newFileMenu;

    /**
     * @brief Menu Aide
     */
    QMenu *m_helpMenu;

    /**
     * @brief Action : Aide > A propos
     */
    QAction *m_aboutAction;

    /**
     * @brief Action : Fichier > Nouveau > MCD
     */
    QAction *m_newMcdAction;

    /**
     * @brief Action : Fichier > Quitter
     */
    QAction *m_quitAction;
};

#endif // MAINWINDOW_H

