#include "inheritenceremovecommand.h"
#include "model/mcdmodel.h"
#include "graphic/inheritencearrowobject.h"
#include "graphic/entity.h"
#include "logic/entity.h"

#include <QGraphicsScene>

using namespace Command;
InheritenceRemoveCommand::InheritenceRemoveCommand(
        Graphic::InheritenceArrowObject* arrow,
        Model::McdModel* model,
        QGraphicsScene* scene,
        QUndoCommand *parent )
    : AbstractRemoveCommand(model, scene, parent)
    , m_arrow(arrow)
{
}

void InheritenceRemoveCommand::~InheritenceRemoveCommand() {
    if(!isApplied()) {
        delete m_arrow;
    }
}

void InheritenceRemoveCommand::undo() {
    AbstractRemoveCommand::undo();
    scene()->addItem(m_arrow);
    auto entity = static_cast<Graphic::Entity*>(m_arrow->source())->entity() ;
    auto prnt = static_cast<Graphic::Entity*>(m_arrow->destination())->entity();
    entity->addParent(prnt);
}

void InheritenceRemoveCommand::redo() {
    AbstractRemoveCommand::redo();
    scene()->removeItem(m_arrow);
    auto entity = static_cast<Graphic::Entity*>(m_arrow->source())->entity() ;
    auto prnt = static_cast<Graphic::Entity*>(m_arrow->destination())->entity();
    entity->removeParent(prnt);
}
