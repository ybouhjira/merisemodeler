#include "stylelistmodel.h"
#include "graphic/style.h"

using namespace Ui;

StyleListModel::StyleListModel(QObject *parent) :
    QAbstractListModel(parent)
{
    m_styles << Graphic::Style::getDefaultStyle();
}

int StyleListModel::rowCount(const QModelIndex&) const {
    return m_styles.size();
}

QVariant StyleListModel::data(const QModelIndex &index, int role) const {
    if(role == Qt::DisplayRole)
        return m_styles[index.row()]->name();
    else
        return QVariant();
}
