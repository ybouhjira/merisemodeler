#include "associationtablemodel.h"

using namespace Ui;
AssociationTableModel::AssociationTableModel(Logic::Association *association,
        QObject *parent)
    : ItemTableModel(parent)
    , m_association(association)
{
}

Logic::Association* AssociationTableModel::item() const {
    return m_association;
}

void AssociationTableModel::setAssociation(Logic::Association *assoc) {
    beginResetModel();
    m_association = assoc;
    endResetModel();
}
