#ifndef ASSOCIATIONEDITWIDGET_H
#define ASSOCIATIONEDITWIDGET_H

#include "itemeditwidget.h"
#include "logic/association.h"
#include "associationtablemodel.h"

// Qt
class QPushButton;
class QTabWidget;
class QTableView;
class QGroupBox;
class QComboBox;

class Ui::AssociationEditWidget : public Ui::ItemEditWidget
{
    Q_OBJECT
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

public slots:
    /**
     * @brief Mutateur
     * @param assoc
     */
    void setAssociation(Logic::Association* assoc);

    /**
     * @brief Met à jour le widget des cardinaliutés
     */
    void updateNames();

    /**
     * @brief Applique les cardinalités
     */
    void applyCardinalities();

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

    /**
     * @brief Affiche les cardinalité de la premiéré entité
     */
    QGroupBox *m_entity1Box;

    /**
     * @brief Affiche les cardinalité de la deuxième entité
     */
    QGroupBox *m_entity2Box;

    /**
     * @brief Case qui contient la cardinalité minimum pour l'entité 1
     */
    QComboBox *m_ent1minComboBox;

    /**
     * @brief Case qui contient la cardinalité maximum pour l'entité 1
     */
    QComboBox *m_ent1maxComBox;

    /**
     * @brief Case qui contient la cardinalité minimum pour l'entité 2
     */
    QComboBox *m_ent2minComboBox;

    /**
     * @brief Case qui contient la cardinalité maximum pour l'entité 2
     */
    QComboBox *m_ent2maxComboBox;

};

#endif // ASSOCIATIONEDITWIDGET_H
