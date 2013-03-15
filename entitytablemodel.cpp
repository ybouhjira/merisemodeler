#include "entitytablemodel.h"
#include "property.h"

EntityTableModel::EntityTableModel(Entity* entity, QObject* parent)
    : QAbstractTableModel(parent)
{
    setEntity(entity);
}

QVariant EntityTableModel::data(const QModelIndex &index, int role) const {
    if(m_entity != nullptr) {
        Property* pty = m_entity->properties()[index.row()];
        switch(role) {
        case Qt::DisplayRole:
            switch(index.column()) {
            case 0:
                return pty->name();
                break;
            case 1:
                return pty->type().name();
                break;
            case 2:
                return pty->isIdentifier();
                break;
            case 3:
                return pty->isObligatory();
                break;
            }
        default:
            return QVariant();
        }
    }else {
        return QVariant();
    }
}

int EntityTableModel::rowCount(const QModelIndex &/*parent*/) const {
    if(m_entity != nullptr)
        return m_entity->properties().size();
    else
        return 0;
}

int EntityTableModel::columnCount(const QModelIndex &/*parent*/) const {
    return 4;
}

QVariant EntityTableModel::headerData
(int section, Qt::Orientation orientation, int role) const {
    switch(role) {
    case Qt::DisplayRole:
        switch(orientation) {
        case Qt::Vertical:
            return section;
            break;
        case Qt::Horizontal:
            switch(section) {
            case 0:
                return tr("Name");
                break;
            case 1:
                return tr("Type");
                break;
            case 2:
                return tr("Id");
                break;
            case 3:
                return tr("Obligatory");
                break;
            default:
                return QVariant();
            }
            break;
        default:
            return QVariant();
            break;
        }
        break;
    default:
        return QVariant();
    }
}

void EntityTableModel::setEntity(Entity *entity) {
    m_entity = entity;
}

void EntityTableModel::addProperty(Property *property) {
    beginResetModel();
    m_entity->addProperty(property);
    endResetModel();
}
