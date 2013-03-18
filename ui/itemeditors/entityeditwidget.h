#ifndef ENTITYEDITWIDGET_H
#define ENTITYEDITWIDGET_H

#include "logic/namespace.h"
#include "itemeditwidget.h"
#include "entitytablemodel.h"

// Qt
class QLineEdit;
class QVBoxLayout;
class QTableView;
class QTabWidget;
class QPushButton;

/**
 * @brief EntityEditWidget est le widget qui permet d'éditer une entité
 */
class Ui::EntityEditWidget : public Ui::ItemEditWidget
{
    Q_OBJECT
public:
    /**
     * @brief Constructeur
     * @param parent
     */
    explicit EntityEditWidget(Logic::Entity* entity = nullptr,
                              QWidget *parent = 0);
    
    /**
     * @brief Accesseur
     * @return L'Entité
     */
    Logic::Entity* item() const;

    /**
     * @reimp
     */
    Ui::EntityTableModel* propertiesModel() const;

    /**
     * @reimp
     */
    void removeSelectedProperties();
    
public slots:
    /**
     * @brief Mutateur
     * @param L'entité
     */
    void setEntity(Logic::Entity* entity);

private slots:
    /**
     * @brief Ajoute une properiété à l'entité lorsque on clique sur le
     * bouton ajouter
     */
    void addProperty();

private:
    /**
     * @brief L'entité
     */
    Logic::Entity* m_entity;

    /**
     * @brief Premier onglet
     */
    QWidget* m_entityPageWidget;

    /**
     * @brief Onglets
     */
    QTabWidget *m_tabWidget;

    /**
     * @brief Table qui affiche les propriétés
     */
    QTableView *m_tableView;

    /**
     * @brief Model qui sert à représenter les donnés pour le QTableView
     */
    Ui::EntityTableModel *m_tableModel;

    /**
     * @brief Bouton Ajouter proriété
     */
    QPushButton *m_addButton;

    /**
     * @brief Bouton supprimer propriété
     */
    QPushButton *m_removeButton;
    
};

#endif // ENTITYEDITWIDGET_H
