#include "addassociationcommand.h"
#include "graphic/association.h"
#include "logic/association.h"
#include "logic/entity.h"
#include "model/mcdmodel.h"
#include "model/mcdscene.h"

using namespace Command;

AddAssociationCommand::AddAssociationCommand(
        Logic::Entity *entity1,
        Logic::Entity *entity2,
        Model::McdModel* mcd,
        QUndoCommand* parent)
    : AddItemCommand(mcd, QObject::tr("Added an association"), parent)
{
    m_association = this->mcd()->createAssociation(entity1, entity2);
    QGraphicsItem* gEnt1 = entity1->graphicObject() ;
    QGraphicsItem* gEnt2 = entity2->graphicObject() ;
    setX((gEnt1->x() + gEnt2->x()) / 2);
    setY((gEnt1->y() + gEnt2->y()) / 2);
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
    auto graphicAssoc = new Graphic::Association(m_association, x(), y());
    mcd()->scene()->addItem(graphicAssoc);
}

Logic::Association* AddAssociationCommand::item() const {
    return m_association;
}
