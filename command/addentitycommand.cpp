#include "addentitycommand.h"
#include "logic/entity.h"
#include "graphic/entity.h"
#include "ui/mcdmodel.h"
#include "ui/mcdgraphicsscene.h"

using namespace Command;

AddEntityCommand::AddEntityCommand(
        qreal x,
        qreal y,
        Ui::McdModel* mcd,
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
    this->mcd()->scene()->removeItem(m_entity->graphicObject());
}

void AddEntityCommand::redo() {
    auto graphicEntity = new Graphic::Entity(m_entity, x(), y());
    mcd()->scene()->addItem(graphicEntity);
}
