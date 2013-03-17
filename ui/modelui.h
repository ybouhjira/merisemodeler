#ifndef MODELUI_H
#define MODELUI_H

#include "namespace.h"

#include <QMainWindow>
class QGraphicsView;

/**
  * @brief ModelUi et la class de l'interface graphique qui permet d'éditer
  * les modèles mcd
  */
class Ui::ModelUi : public QMainWindow
{
    // METHODS
protected:
    /**
      * @brief Constructeur
      * @param parent Widget parent
      */
    explicit ModelUi(QWidget *parent = 0);

    /**
     * @brief Destructeur
     */
    virtual ~ModelUi();

private slots:
    /**
     * @brief Affiche une boite de dialogue pour exporter le model
     */
    void showExportDialog();

    // ATTRIBUTS
protected:
    /**
      * @brief Le widget qui affiche le diagram
      */
    QGraphicsView *m_graphicsView;

    /**
      * @brief Barre d'outils
      */
    QToolBar *m_toolBar;

    /**
     * @brief Action pour exporter le model en PDF, SVG ou autre
     */
    QAction *m_exportAction;
};

#endif // MODELUI_H
