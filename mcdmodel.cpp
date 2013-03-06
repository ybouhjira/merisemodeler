#include "mcdmodel.h"
#include "item.h"
#include "entity.h"
#include "mcdgraphicsscene.h"

// Qt
#include <QRegExp>

McdModel::McdModel(QObject *parent)
    : QObject(parent)
    , m_scene(new McdGraphicsScene(this))
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
    delete m_items[index];
    m_items.removeAt(index);
    emit itemRemoved(index);
}

void McdModel::removeItem(Item *item) {
    for (int i = 0; i < m_items.size(); ++i) {
        if( item == m_items[i]) {
            delete m_items[i];
            m_items.removeAt(i);
            emit itemRemoved(i);
            return;
        }
    }
}

McdGraphicsScene* McdModel::scene() const {
    return m_scene;
}

void McdModel::createNewEntity() {
    QString entityName = tr("Entity");

    // Recherche de noms similaires
    while(bool similarName = true) {
        // Iterer sur tous les elements
        int i;
        for (i = 0; i < m_items.size() ; ++i) {
            if(m_items[i]->name() == entityName) {
                entityName.replace(
                            QRegExp("(\\d*)$"),
                            QString::number(QString("\\1").toInt() + 1)
                            );
            }
        }
        // Si aucun non similaire trouvé
        if(i == m_items.size()) {
            similarName = false;
        }
    }

    m_items.append(new Entity(entityName));
}
