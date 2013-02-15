#ifndef MODELUI_H
#define MODELUI_H

#include <QMainWindow>
class QGraphicsView;

/**
 * @brief This is The base class for Merise Models User Interfaces
 * It's subclasses QMainWindow to provide a UI with a QGraphicsView as it's
 * central widget and a QToolBar for the tools
 */
class ModelUi : public QMainWindow
{
// METHODS =====================================================================
protected:
    explicit ModelUi(QWidget *parent = 0);

// ATTRIBUTS ===================================================================
protected:
    QGraphicsView *m_graphicsView;
    QToolBar *m_toolBar;
};

#endif // MODELUI_H
