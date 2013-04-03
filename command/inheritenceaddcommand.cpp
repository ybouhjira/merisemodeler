#include "inheritenceaddcommand.h"
#include "graphic/inheritencearrowobject.h"
#include "logic/entity.h"

#include <QGraphicsScene>

using namespace Command;

InheritenceAddCommand::InheritenceAddCommand(
        Logic::Entity* entity1,
        Logic::Entity* entity2,
        Model::McdModel* mcd,
        QGraphicsScene *scene,
        QUndoCommand* parent)
    : ItemCommand(mcd, scene, QObject::tr("Added inheritence"), parent)
    , m_arrow(new Graphic::InheritenceArrowObject(entity1->graphicObject(), entity2->graphicObject()))
    , m_entity1(entity1)
    , m_entity2(entity2)
{
}

InheritenceAddCommand::~InheritenceAddCommand() {
    if(!isApplied())
        delete m_arrow;
}

void InheritenceAddCommand::undo() {
    ItemCommand::undo();
    scene()->removeItem(m_arrow);
    m_entity1->removeParent(m_entity2);
}

void InheritenceAddCommand::redo() {
    ItemCommand::redo();

    scene()->addItem(m_arrow);
    m_entity1->addParent(m_entity2);
}
