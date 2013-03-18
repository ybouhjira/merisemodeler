#include "entitytablemodel.h"
#include "logic/property.h"
#include "logic/typefactory.h"
#include "logic/invalidtypestringexception.h"
#include <QModelIndex>

using namespace Logic;
using namespace Ui;

EntityTableModel::EntityTableModel(Entity* entity, QObject* parent)
    : ItemTableModel(parent)
{
    setEntity(entity);
}

Logic::Entity* EntityTableModel::item() const {
    return m_entity;
}

QVariant EntityTableModel::data(const QModelIndex &index, int role) const {
    if(m_entity == nullptr)
        return QVariant();

    int row = index.row();
    int column = index.column();
    Property* pty = m_entity->properties()[index.row()];

    switch(column) {
    case 0:
        if(role == Qt::CheckStateRole)
            return pty->isIdentifier()? Qt::Checked : Qt::Unchecked;
        else
            return QVariant();
    default:
        auto newIndex = createIndex(row, column - 1, index.internalPointer());
        return ItemTableModel::data(newIndex, role);
    }
}

int EntityTableModel::columnCount(const QModelIndex &/*parent*/) const {
    return 5;
}

QVariant EntityTableModel::headerData
(int section, Qt::Orientation orientation, int role) const
{
    if(section == 0 && orientation == Qt::Horizontal) {
        return (role == Qt::DisplayRole)? tr("id") : QVariant();
    } else {
        section = (orientation == Qt::Horizontal)? section - 1 : section;
        return ItemTableModel::headerData(section , orientation, role);
    }
}

void EntityTableModel::setEntity(Entity *entity) {
    m_entity = entity;
}

Qt::ItemFlags EntityTableModel::flags(const QModelIndex &i) const {
    switch(i.column()) {
    case 0: //< Nom
        return Qt::ItemIsEnabled | Qt::ItemIsUserCheckable;
    default:
        auto newIndex = createIndex(i.row(), i.column()-1, i.internalPointer());
        return ItemTableModel::flags(newIndex);
    }
}

bool EntityTableModel::setData
(const QModelIndex &i, const QVariant &value, int role)
{
    Property* property = m_entity->properties()[i.row()] ;

    switch(i.column()) {
    case 0:
        property->setIsIdentifier(value.toBool());
        emit dataChanged(i, i, {role});
        return true;
    default:
        auto newIndex = createIndex(i.row(), i.column()-1, i.internalPointer());
        return ItemTableModel::setData(newIndex, value, role);
    }
}
