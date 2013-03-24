#include "removeitemscommand.h"
#include "model/mcdmodel.h"
#include "logic/item.h"

using namespace Command;
RemoveItemsCommand::RemoveItemsCommand(
        QList<Logic::Item*> items,
        Model::McdModel* mcd,
        QUndoCommand* parent)
    : McdCommand(mcd, QObject::tr("Remove items"), parent)
    , m_items(items)
{
}

RemoveItemsCommand::~RemoveItemsCommand() {
    if(!isApplied())
        for(Logic::Item* item : m_items)
            delete item;
}

void RemoveItemsCommand::undo() {
    McdCommand::undo();
    for(Logic::Item* item : m_items) {
        mcd()->addItem(item);
    }
}

void RemoveItemsCommand::redo() {
    McdCommand::redo();
    for(Logic::Item* item : m_items) {
        mcd()->removeItem(item);
    }
}
