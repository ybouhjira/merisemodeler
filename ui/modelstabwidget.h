#ifndef MODELSTABWIDGET_H
#define MODELSTABWIDGET_H

#include "namespace.h"
#include "model/namespace.h"
#include "model/namespace.h"

// Qt
#include <QWidget>
#include <QList>
class QTabBar;
class QGraphicsScene;

/**
 * @brief Widget qui permet de parcourir les models avec des onglets
 */
class Ui::ModelsTabWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ModelsTabWidget(QWidget *parent = 0);
    
signals:
    
public slots:
    /**
     * @brief Ajouter une model
     * @param label Nom affiché dans l'onglet
     * @param model Model
     */
    void addModel(QString const& label,
                  Model::McdModel* model,
                  QGraphicsScene *scene);

    /**
     * @brief Supprime une model
     * @param index Indice
     */
    void removeModel(int index);

    //ATTRIBUTS
private:
    /**
     * @brief Barre d'onglets
     */
    QTabBar *m_tabBar;
    
    /**
     * @brief Models
     */
    QList<Model::McdModel*> m_models;
};

#endif // MODELSTABWIDGET_H
