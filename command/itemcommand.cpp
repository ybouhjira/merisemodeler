#include "itemcommand.h"

using namespace Command;

ItemCommand::ItemCommand(
        Model::McdModel* mcd,
        QGraphicsScene* scene,
        QString const& text,
        QUndoCommand* parent)
    : McdCommand(mcd, text, parent)
    , m_scene(scene)
{
}

ItemCommand::~ItemCommand() {
}

QGraphicsScene* ItemCommand::scene() const {
    return m_scene;
}
