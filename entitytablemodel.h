#ifndef ENTITYTABLEMODEL_H
#define ENTITYTABLEMODEL_H

#include "entity.h"
#include <QAbstractTableModel>

class EntityTableModel : public QAbstractTableModel
{
public:
    /**
     * @brief Constructeur
     * @param entity L'entité qui va etre source des données de ce model
     * @param parent QObject parent
     */
    explicit EntityTableModel(
            Entity* entity = nullptr,
            QObject* parent = nullptr);

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
    QVariant headerData(int section,
                        Qt::Orientation orientation, int role) const override;

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
     * @brief Change l'entité en plus d'établir la connexion avec les
     * signaux qui sont emis lors du changement de cette dernière
     */
    void setEntity(Entity* entity);

    /**
     * @brief Ajoute la propriété a l'entité
     * @param pty Properiété
     */
    void addProperty(Property* property);

private:
    /**
     * @brief Entité
     */
    Entity *m_entity;
};

#endif // ENTITYTABLEMODEL_H
