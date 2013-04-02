#include "associationremovecommand.h"
#include "entityremovecommand.h"
#include "inheritenceremovecommand.h"
// Model
#include "model/mcdmodel.h"
// Graphic
#include "graphic/inheritencearrowobject.h"
// Logic
#include "logic/entity.h"
#include "logic/association.h"
// Qt
#include <QGraphicsScene>

using namespace Command;
EntityRemoveCommand::EntityRemoveCommand(
        Logic::Entity *entity,
        Model::McdModel* model,
        QGraphicsScene* scene,
        QUndoCommand *parent)
    : AbstractRemoveCommand(model, scene, parent)
    , m_entity(entity)
{
    // Supprimer les asssociations
    for(int i=0; i<model->items().size(); i++) {
        auto assoc = dynamic_cast<Logic::Association*>(model->items()[i]);
        if(assoc != nullptr) {
            new AssociationRemoveCommand(assoc, model, scene, this);
        }
    }


    // SUpprimer les fléches d'héritage
    for(int i=0; i<scene->items().size(); i++) {
        auto arrow = dynamic_cast<Graphic::InheritenceArrowObject*>(scene->items()[i]);
        if(arrow != nullptr) {
            new InheritenceRemoveCommand(arrow, model, scene, parent);
        }
    }
}

EntityRemoveCommand::~EntityRemoveCommand() {
    if(!isApplied()) {
        delete m_entity->graphicObject();
        delete m_entity;
    }
}

void EntityRemoveCommand::undo() {
    AbstractRemoveCommand::undo();
    mcd()->addItem(m_entity);
    scene()->addItem(m_entity->graphicObject());
}

void EntityRemoveCommand::redo() {
    AbstractRemoveCommand::redo();
    mcd()->removeItem(m_entity);
    scene()->removeItem(m_entity->graphicObject());
}
