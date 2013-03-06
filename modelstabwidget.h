#ifndef MODELSTABWIDGET_H
#define MODELSTABWIDGET_H

class McdModel;

// Qt
#include <QWidget>
#include <QList>
class QTabBar;

/**
 * @brief Widget qui permet de parcourir les models avec des onglets
 */
class ModelsTabWidget : public QWidget
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
    void addModel(QString const& label, McdModel* model);

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
    QList<McdModel*> m_models;
};

#endif // MODELSTABWIDGET_H
