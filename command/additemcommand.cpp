#include "additemcommand.h"

using namespace Command;

AddItemCommand::AddItemCommand(
        Model::McdModel* mcd,
        QGraphicsScene* scene,
        QString const& text,
        QUndoCommand* parent)
    : McdCommand(mcd, text, parent)
    , m_scene(scene)
{
}

AddItemCommand::~AddItemCommand() {
}

QGraphicsScene* AddItemCommand::scene() const {
    return m_scene;
}
