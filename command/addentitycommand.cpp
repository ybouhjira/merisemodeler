#include "addentitycommand.h"
#include "logic/entity.h"
#include "graphic/entity.h"
#include "model/mcdmodel.h"

// Qt
#include <QGraphicsScene>

using namespace Command;

AddEntityCommand::AddEntityCommand(
        qreal x,
        qreal y,
        Model::McdModel* model,
        QGraphicsScene* scene,
        QUndoCommand* parent)
    : AddItemCommand(model, scene, QObject::tr("Added an entity"), parent)
{
    // Recherche de nom similaire à entityName
    // si trouvé on modifie nameSuffix
    QString entityName = QObject::tr("Entity");
    QString nameSuffix = "" ;
    QListIterator<Logic::Item*> iterator(mcd()->items());
    while(iterator.hasNext()) {
        while(iterator.hasNext()) {
            if(iterator.next()->name()  == entityName + nameSuffix) {
                nameSuffix = QString::number(nameSuffix.toInt() + 1);
                iterator.toFront(); //< revenir au premier
                break;
            }
        }
    }

    // LOGIC
    m_entity = new Logic::Entity(entityName + nameSuffix) ;

    // GRAPHIC
    m_entity->setGraphicObject(new Graphic::Entity(m_entity, x, y));
}

AddEntityCommand::~AddEntityCommand() {
    if(!isApplied()) {
        delete m_entity->graphicObject();
        delete m_entity;
    }
}

void AddEntityCommand::undo() {
    AddItemCommand::undo();
    scene()->removeItem(m_entity->graphicObject());
    mcd()->removeItem(m_entity);
}

void AddEntityCommand::redo() {
    AddItemCommand::redo();
    mcd()->addItem(m_entity);
    scene()->addItem(m_entity->graphicObject());
}
