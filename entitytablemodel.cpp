#include "entitytablemodel.h"
#include "property.h"

using namespace Logic;

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
            case 4:
                return pty->defaultValue();
            default:
                return QVariant();
            }
        case Qt::CheckStateRole:
            switch(index.column()) {
            case 2:
                return pty->isIdentifier()? Qt::Checked : Qt::Unchecked;
                break;
            case 3:
                return pty->isObligatory()? Qt::Checked : Qt::Unchecked;
                break;
            default:
                return QVariant();
            }
        default:
            return QVariant();
        }
    } else {
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
    return 5;
}

QVariant EntityTableModel::headerData
(int section, Qt::Orientation orientation, int role) const {
    switch(role) {
    case Qt::DisplayRole:
        switch(orientation) {
        case Qt::Vertical:
            return section + 1;
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
                return tr("id");
                break;
            case 3:
                return tr("Obligatory");
                break;
            case 4:
                return tr("Default");
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
    if(m_entity != nullptr) {
        beginResetModel();
        m_entity->addProperty(property);
        endResetModel();
    }
}

Qt::ItemFlags EntityTableModel::flags(const QModelIndex &index) const {
    switch(index.column()) {
    case 0: //< Nom
    case 1: //< Type
    case 4: //< Default
        return Qt::ItemIsEditable | Qt::ItemIsEnabled;
        break;
    case 2: //< id
    case 3: // oblig
        return Qt::ItemIsEnabled
                | Qt::ItemIsUserCheckable;
        break;
    default:
        return Qt::NoItemFlags;
    }
}

bool EntityTableModel::setData
(const QModelIndex &index, const QVariant &value, int role)
{
    // La properiété à changer
    Property* property = m_entity->properties()[index.row()] ;

    bool sucssesfulChange = false;

    switch(index.column()) {
    case 0:
        property->setName(value.toString());
        sucssesfulChange = true;
        break;
    case 1:
        return false;
        break;
    case 2:
        property->setIsIdentifier(value.toBool());
        sucssesfulChange = true;
        break;
    case 3:
        property->setIsObligatory(value.toBool());
        sucssesfulChange = true;
        break;
    case 4:
        property->setDefaultValue(value.toString());
        sucssesfulChange = true;
        break;
    }
    if(sucssesfulChange) {
        emit dataChanged(index, index, {role});
        return true;
    }
    return false;
}
