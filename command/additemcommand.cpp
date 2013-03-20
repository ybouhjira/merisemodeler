#include "additemcommand.h"

using namespace Command;

AddItemCommand::AddItemCommand(
        Ui::McdModel* mcd,
        QString const& text,
        QUndoCommand* parent = nullptr)
    : McdCommand(mcd, text, parent)
{
}

AddItemCommand::~AddItemCommand() {

}
