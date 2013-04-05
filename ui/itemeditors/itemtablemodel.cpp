#include "itemtablemodel.h"
#include "logic/property.h"
#include "logic/typefactory.h"
#include "logic/invalidtypestringexception.h"

using namespace Logic;
using namespace Ui;

ItemTableModel::ItemTableModel( QObject* parent) : QAbstractTableModel(parent) { }

ItemTableModel::~ItemTableModel() { }

QVariant ItemTableModel::data(const QModelIndex &index, int role) const {
    if(item() != nullptr) {
        Property* pty = item()->properties()[index.row()];
        switch(role) {
        case Qt::DisplayRole:
            switch(index.column()) {
            case 0:
                return pty->name();
                break;
            case 1:
                return pty->type();
                break;
            case 4:
                return pty->defaultValue();
            default:
                return QVariant();
            }
        case Qt::CheckStateRole:
            switch(index.column()) {
            case 2:
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

int ItemTableModel::rowCount(const QModelIndex &/*parent*/) const {
    if(item() != nullptr)
        return item()->properties().size();
    else
        return 0;
}

int ItemTableModel::columnCount(const QModelIndex &/*parent*/) const {
    return 4;
}

QVariant ItemTableModel::headerData
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
                return tr("Obligatory");
                break;
            case 3:
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

Qt::ItemFlags ItemTableModel::flags(const QModelIndex &index) const {
    switch(index.column()) {
    case 0: //< Nom
    case 1: //< Type
    case 4: //< Default
        return Qt::ItemIsEditable | Qt::ItemIsEnabled | Qt::ItemIsSelectable;
        break;
    case 2: //< oblig
        return Qt::ItemIsEnabled | Qt::ItemIsUserCheckable | Qt::ItemIsSelectable ;
        break;
    default:
        return Qt::ItemIsSelectable;
    }
}

bool ItemTableModel::setData (const QModelIndex &index, const QVariant &value, int role) {
    try {
        // La properiété à changer
        Property* property = item()->properties()[index.row()] ;

        bool sucssesfulChange = false;

        switch(index.column()) {
        case 0:
            if(!value.toString().isEmpty()) {
                property->setName(value.toString());
                sucssesfulChange = true;
            }
            break;
        case 1:
            property->setType(value.toString());
            return true;
            break;
        case 2:
            property->setIsObligatory(value.toBool());
            sucssesfulChange = true;
            break;
        case 3:
            property->setDefaultValue(value.toString());
            sucssesfulChange = true;
            break;
        }
        if(sucssesfulChange) {
            emit dataChanged(index, index, {role});
            return true;
        }
        return false;
    } catch (Logic::InvalidTypeStringException &) {
        return false;
    }
}

void ItemTableModel::addProperty(Property *property) {
    if(item() != nullptr) {
        beginResetModel();
        item()->addProperty(property);
        endResetModel();
    }
}

void ItemTableModel::removeProperty(int index) {
    if(item()!= nullptr) {
        beginResetModel();
        item()->removeProperty(index);
        endResetModel();
    }
}
