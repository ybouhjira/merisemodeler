#ifndef MODELUI_H
#define MODELUI_H

#include <QMainWindow>
class QGraphicsView;

/**
  * @brief ModelUi et la class de l'interface graphique qui permet d'éditer
  * les modèles mcd
  */
class ModelUi : public QMainWindow
{
// METHODS
protected:
    /**
      * @brief Constructeur
      * @param parent Widget parent
      */
    explicit ModelUi(QWidget *parent = 0);

// ATTRIBUTS
protected:
    /**
      * @brief Le widget qui affiche le MCD
      */
    QGraphicsView *m_graphicsView;

    /**
      * @brief Barre d'outils
      */
    QToolBar *m_toolBar;
};

#endif // MODELUI_H
