#include "addassociationcommand.h"
#include "graphic/association.h"
#include "logic/association.h"
#include "logic/entity.h"
#include "ui/mcdmodel.h"
#include "ui/mcdgraphicsscene.h"

using namespace Command;

AddAssociationCommand::AddAssociationCommand(
        Logic::Entity *entity1,
        Logic::Entity *entity2,
        Ui::McdModel* mcd,
        QUndoCommand* parent)
    : AddItemCommand(mcd, QObject::tr("Added an association"), parent)
{
    m_association = this->mcd()->createAssociation(entity1, entity2);
    qreal x = entity1->graphicObject()->x() + entity2->graphicObject()->x() / 2;
    qreal y = entity1->graphicObject()->y() + entity2->graphicObject()->y() / 2;
    setX(x);
    setY(y);
}

AddAssociationCommand::~AddAssociationCommand() {
    if(!isApplied())
        delete m_association;
}

void AddAssociationCommand::undo() {
    AddItemCommand::undo();
    mcd()->scene()->removeItem(m_association->graphicObject());
    mcd()->removeItem(m_association);
}

void AddAssociationCommand::redo() {
    AddItemCommand::redo();
    mcd()->addItem(m_association);
    auto graphicEntity = new Graphic::Association(m_association, x(), y());
    mcd()->scene()->addItem(graphicEntity);
}
