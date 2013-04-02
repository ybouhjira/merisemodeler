#include "abstractremovecommand.h"

using namespace Command;

AbstractRemoveCommand::AbstractRemoveCommand(
        Model::McdModel* model,
        QGraphicsScene* scene,
        QUndoCommand *parent)
    : ItemCommand(model, scene, QObject::tr("Delete"), parent)
{
}
