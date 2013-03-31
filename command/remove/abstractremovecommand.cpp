#include "abstractremovecommand.h"

using namespace Command;

AbstractRemoveCommand::AbstractRemoveCommand(
        Model::McdModel* model,
        QGraphicsScene* scene,
        QUndoCommand *parent)
    : ItemCommand(mode, scene, parent)
{
}
