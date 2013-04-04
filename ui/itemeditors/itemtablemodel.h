#ifndef ITEMTABLEMODEL_H
#define ITEMTABLEMODEL_H

#include "ui/namespace.h"
#include "logic/item.h"
#include <QAbstractTableModel>

class Ui::ItemTableModel : public QAbstractTableModel
{
public:
    /**
     * @brief Constructeur
     * @param entity L'entité qui va etre source des données de ce model
     * @param parent QObject parent
     */
    explicit ItemTableModel(QObject* parent = nullptr);

    /**
     * @brief Destructeur
     */
    virtual ~ItemTableModel();

    // Méthodes virtuelles
    virtual Logic::Item* item() const = 0 ;

    // Redéfinitions
    /**
     * @reimp
     * @brief Renvoie les données
     */
    QVariant data(const QModelIndex &index, int role) const override;

    /**
     * @reimp
     * @brief Renvoie le nombre de lignes
     */
    int rowCount(const QModelIndex &parent) const override;

    /**
     * @reimp
     * @brief Renvoie le nombre de colonne
     */
    int columnCount(const QModelIndex &parent) const override;

    /**
     * @reimp
     * @brief Renvoie les titres des colonnes et les nombre des lignes
     */
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

    /**
     * @reimp
     * @brief implmenté pour indiquer que les deux dernières colonnes doivent
     * etre representés sous forme de checkbox
     */
    Qt::ItemFlags flags(const QModelIndex &index) const override;

    /**
     * @reimp
     */
    bool setData(const QModelIndex &index, const QVariant &value, int role);

public slots:

    /**
     * @brief Ajoute la propriété a l'entité
     * @param pty Properiété
     */
    void addProperty(Logic::Property* property);

    /**
     * @brief Remove Supprime une proprièté
     * @param index indice
     */
    void removeProperty(int index);

};

#endif // ITEMTABLEMODEL_H
