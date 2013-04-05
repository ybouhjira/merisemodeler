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


Graphic::Style* StyleListModel::styleAt(int index) const {
    return m_styles[index];
}

bool StyleListModel::setData(const QModelIndex &index, const QVariant &value, int role) {
    if (index.row() < m_styles.size() && role == Qt::EditRole ) {
        m_styles[index.row()]->setName(value.toString());
        return true;
    } else {
        return false;
    }
}

void StyleListModel::addStyle() {
    beginResetModel();
    Graphic::Style *d = Graphic::Style::getDefaultStyle();
    auto style =  new Graphic::Style(d->brush(), d->pen(), d->font(), this);
    style->setName("Style");
    m_styles << style;
    endResetModel();
}

void StyleListModel::removeStyle(int index) {
    beginResetModel();
    if(index < m_styles.size() && index >= 0) {
        delete m_styles.at(index);
        m_styles.removeAt(index);
    }
    endResetModel();
}

Qt::ItemFlags StyleListModel::flags(const QModelIndex &) const {
    return Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled;
}
