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
    explicit StyleListModel(QObject *parent = 0);
    
    int rowCount(const QModelIndex&) const;

    QVariant data(const QModelIndex &index, int role) const;

    Graphic::Style* styleAt(int index) const ;
    
private:
    QList<Graphic::Style*> m_styles;
};

#endif // STYLELISTMODEL_H
