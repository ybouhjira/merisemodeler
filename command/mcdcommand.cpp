#include "mcdcommand.h"

using namespace Command;

McdCommand::McdCommand(Ui::McdModel* mcd,
                       QString const& text,
                       QUndoCommand* parent)
    : QUndoCommand(text, parent)
    , m_mcd(mcd)
{
}

McdCommand::~McdCommand()
{
}

Ui::McdModel* McdCommand::mcd() const{
    return m_mcd;
}
