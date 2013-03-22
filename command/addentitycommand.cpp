#include "addentitycommand.h"
#include "logic/entity.h"
#include "graphic/entity.h"
#include "model/mcdmodel.h"
#include "model/mcdscene.h"

using namespace Command;

AddEntityCommand::AddEntityCommand(
        qreal x,
        qreal y,
        Model::McdModel* mcd,
        QUndoCommand* parent)
    : AddItemCommand(mcd, QObject::tr("Added an entity"), parent)
{
    m_entity = this->mcd()->createEntity();
    setX(x);
    setY(y);
}

AddEntityCommand::~AddEntityCommand() {
    if(!isApplied())
        delete m_entity;
}

void AddEntityCommand::undo() {
    AddItemCommand::undo();
    mcd()->scene()->removeItem(m_entity->graphicObject());
    mcd()->removeItem(m_entity);
}

void AddEntityCommand::redo() {
    AddItemCommand::redo();
    mcd()->addItem(m_entity);
    auto graphicEntity = new Graphic::Entity(m_entity, x(), y());
    mcd()->scene()->addItem(graphicEntity);
}

Logic::Entity* AddEntityCommand::item() const {
    return m_entity;
}
