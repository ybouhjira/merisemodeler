#include "mcdmodel.h"
#include "logic/entity.h"
#include "logic/association.h"
#include "logic/associationlink.h"
#include "mcdgraphicsscene.h"

// Qt
#include <QRegularExpression>
#include <QRegularExpressionMatch>

using namespace Logic;
using namespace Ui;

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

Entity* McdModel::createEntity() {
    QString entityName = tr("Entity");
    QString nameSuffix = "" ;

    QListIterator<Item*> iterator(m_items);
    while(iterator.hasNext()) {
        while(iterator.hasNext()) {
            if(iterator.next()->name()  == entityName + nameSuffix) {
                nameSuffix = QString::number(nameSuffix.toInt() + 1);
                iterator.toFront();
                break;
            }
        }
    }

    // Ajout de l'entité au Model
    auto entity = new Entity(entityName + nameSuffix) ;
    m_items.append(entity);
    return entity;
}

Association* McdModel::createAssociation(Entity *first, Entity *second) {
    QString assocName = tr("Association");
    QString nameSuffix = "";

    QListIterator<Item*> iterator(m_items);
    while(iterator.hasNext()) {
        while(iterator.hasNext()) {
            if(iterator.next()->name()  == assocName + nameSuffix) {
                nameSuffix = QString::number(nameSuffix.toInt() + 1);
                iterator.toFront();
                break;
            }
        }
    }

    QString name = assocName + nameSuffix ;
    Association *association = new Association(name, first, second);
    addItem(association);
    return association;
}
