#ifndef ITEMEDITWIDGET_H
#define ITEMEDITWIDGET_H

#include "namespace.h"
#include "logic/namespace.h"

// Qt
#include <QWidget>
class QAbstractItemModel;
class QLineEdit;

/**
 * @brief ItemEditWidget est classe abstraite qui définit une interface que
 * que doivent implémenté les widget qui veulent édité des elements de type
 * Logic::Item
 */
class Ui::ItemEditWidget : public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief Constructeur
     * @param parent Widget parent
     */
    explicit ItemEditWidget(QWidget *parent = 0);
    
    // Méthodes virtuelles
    virtual Logic::Item* item() const = 0;

    /**
     * @return Retourne le model qui permet d'éditer les propriétés de l'élément
     */
    virtual QAbstractItemModel* propertiesModel() const = 0 ;

    /**
     * @brief Ajoute une propriété à l'élément
     * @remarks Vous devez emettre le signal itemEdited() si l'element à été
     * édité avec succés
     */
    virtual void addProperty() = 0;

    /**
     * @brief Supprime les propriétés selectionnées
     */
    virtual void removeSelectedProperties() = 0;

    // Méthodes concretes
protected:
    QLineEdit* nameLineEdit() const;

signals:
    /**
     * @brief Element modifié
     */
    void itemEdited();

    /**
     * @brief Element changé
     */
    void itemChanged();

private:
    QLineEdit* m_nameLineEdit;
};

#endif // ITEMEDITWIDGET_H
