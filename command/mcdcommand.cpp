#include "mcdcommand.h"

using namespace Command;

McdCommand::McdCommand(Ui::McdModel* mcd,
                       QString const& text,
                       QUndoCommand* parent)
    : QUndoCommand(text, parent)
    , m_mcd(mcd)
    , m_applied(true)
{
}

McdCommand::~McdCommand()
{
}

Ui::McdModel* McdCommand::mcd() const{
    return m_mcd;
}

void McdCommand::undo() {
    m_applied = false;
    QUndoCommand::undo();
}

void McdCommand::redo() {
    m_applied = true;
    QUndoCommand::redo();
}

bool McdCommand::isApplied() const {
    return m_applied;
}

void McdCommand::setApplied(bool applied) {
    m_applied = applied;
}


