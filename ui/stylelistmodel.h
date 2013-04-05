#ifndef STYLELISTMODEL_H
#define STYLELISTMODEL_H

#include "ui/namespace.h"
#include "graphic/namespace.h"

#include <QAbstractListModel>
#include <QList>

/**
 * @brief Modèle des styles
 */
class Ui::StyleListModel : public QAbstractListModel
{
    Q_OBJECT
public:

    /**
     * @brief Constructor
     * @param parent
     */
    explicit StyleListModel(QObject *parent = 0);

    /**
     * @brief Accesseur
     */
    Graphic::Style* styleAt(int index) const;

    // Rdéfinition
    int rowCount(const QModelIndex&) const override;

    QVariant data(const QModelIndex &index, int role) const override;

    bool setData(const QModelIndex &index, const QVariant &value, int role) override;

    Qt::ItemFlags flags(const QModelIndex &) const;

public slots:
    /**
     * @brief Ajoute un style
     */
    void addStyle();

    /**
     * @brief removeStyle
     */
    void removeStyle(int index);
private:
    QList<Graphic::Style*> m_styles;
};

#endif // STYLELISTMODEL_H
