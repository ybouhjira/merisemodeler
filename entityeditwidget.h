#ifndef ENTITYEDITWIDGET_H
#define ENTITYEDITWIDGET_H

class Entity;
class EntityTableModel;

// Qt
#include <QWidget>
class QLineEdit;
class QVBoxLayout;
class QTableView;
class QTabWidget;
class QPushButton;

/**
 * @brief EntityEditWidget est le widget qui permet d'éditer une entité
 */
class EntityEditWidget : public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief Constructeur
     * @param parent
     */
    explicit EntityEditWidget(Entity* entity = nullptr,
                              QWidget *parent = 0);
    
    /**
     * @brief Accesseur
     * @return L'Entité
     */
    Entity* entity() const;
signals:
    /**
     * @brief L'entité à été changé par une autre
     * @param entity Nouvelle entité
     */
    void entityChanged(Entity* entity);

    /**
     * @brief Emit lorsque l'entité est éditée
     * @param entity L'entité edité
     */
    void entityEdited(Entity* entity);
    
public slots:
    /**
     * @brief Mutateur
     * @param L'entité
     */
    void setEntity(Entity* entity);

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
    Entity* m_entity;

    /**
     * @brief Premier onglet
     */
    QWidget* m_entityPageWidget;

    /**
     * @brief Onglets
     */
    QTabWidget *m_tabWidget;

    /**
     * @brief Case su nom
     */
    QLineEdit *m_nameLineEdit;

    /**
     * @brief Table qui affiche les propriétés
     */
    QTableView *m_tableView;

    /**
     * @brief Model qui sert à représenter les donnés pour le QTableView
     */
    EntityTableModel *m_tableModel;

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
