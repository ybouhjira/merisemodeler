#include "mcdmodel.h"
#include "logic/entity.h"
#include "logic/association.h"
#include "logic/associationlink.h"

// Qt
#include <QRegularExpression>
#include <QRegularExpressionMatch>

using namespace Logic;
using namespace Model;

McdModel::McdModel(QObject *parent)
    : QObject(parent)
{
}

McdModel::~McdModel() {
}

QList<Item*> McdModel::items() const {
    return m_items;
}

void McdModel::addItem(Item *item) {
    item->setParent(this);
    m_items.append(item);
}

void McdModel::removeItem(int index) {
    m_items.removeAt(index);
    emit itemRemoved(index);
}

void McdModel::removeItem(Item *item) {
    for (int i = 0; i < m_items.size(); ++i) {
        if( item == m_items[i]) {
            m_items.removeAt(i);
            emit itemRemoved(i);
            return;
        }
    }
}

