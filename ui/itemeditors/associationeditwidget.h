#ifndef ASSOCIATIONEDITWIDGET_H
#define ASSOCIATIONEDITWIDGET_H

#include "itemeditwidget.h"
#include "logic/association.h"
#include "associationtablemodel.h"

// Qt
class QPushButton;
class QTabWidget;
class QTableView;

class Ui::AssociationEditWidget : public Ui::ItemEditWidget
{
public:
    /**
     * @brief Constructeur
     * @param assoc Association à éditer
     * @param parent widget Parent
     */
    AssociationEditWidget(
            Logic::Association *assoc = nullptr,
            QWidget* parent = nullptr);

    // Redéfinitions
    /**
     * @reimp
     */
    Logic::Association* item() const override;

    Ui::AssociationTableModel* propertiesModel() const ;

    void addProperty();

    void removeSelectedProperties();

public slots:
    void setAssociation(Logic::Association* assoc);

    // ATTRIBUTS:
private:
    /**
     * @brief L'association
     */
    Logic::Association* m_association;

    /**
     * @brief Model des propriétés
     */
    Ui::AssociationTableModel* m_tableModel;

    /**
     * @brief Pages du QTabWidget
     */
    QWidget *m_page1Widget, *m_page2Widget;

    /**
     * @brief Onglets
     */
    QTabWidget* m_tabWidget;

    /**
     * @brief Bouton ajouter
     */
    QPushButton *m_addButton;

    /**
     * @brief Bouton supprimer
     */
    QPushButton *m_removeButton;

    /**
     * @brief Table des propriétés
     */
    QTableView *m_tableView;

};

#endif // ASSOCIATIONEDITWIDGET_H
