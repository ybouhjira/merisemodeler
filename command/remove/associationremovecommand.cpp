#include "associationremovecommand.h"
#include "graphic/association.h"
#include "logic/association.h"
#include <QGraphicsScene>
#include "model/mcdmodel.h"

using namespace Command;
AssociationRemoveCommand::AssociationRemoveCommand(
        Logic::Association* association,
        Model::McdModel* model,
        QGraphicsScene* scene,
        QUndoCommand *parent):
    AbstractRemoveCommand(model, scene, parent)
  , m_association(association)
{
}

AssociationRemoveCommand::~AssociationRemoveCommand() {
    if(isApplied()) {
        delete m_association->graphicObject();
        delete m_association;
    }
}

void AssociationRemoveCommand::undo() {
    AbstractRemoveCommand::undo();
    mcd()->addItem(m_association);
    scene()->addItem(m_association->graphicObject());
    scene()->update(0, 0, scene()->width(), scene()->height());
}

void AssociationRemoveCommand::redo() {
    AbstractRemoveCommand::redo();
    mcd()->removeItem(m_association);
    scene()->removeItem(m_association->graphicObject());
    scene()->update(0, 0, scene()->width(), scene()->height());
}
