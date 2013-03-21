#include "additemcommand.h"

using namespace Command;

AddItemCommand::AddItemCommand(
        Ui::McdModel* mcd,
        QString const& text,
        QUndoCommand* parent)
    : McdCommand(mcd, text, parent)
{
}

AddItemCommand::~AddItemCommand() {

}

qreal AddItemCommand::x() const {
    return m_x;
}

qreal AddItemCommand::y() const {
    return m_y;
}

void AddItemCommand::setX(qreal x) {
    m_x = x;
}

void AddItemCommand::setY(qreal y) {
    m_y = y;
}
