#include "mcdcontroller.h"
#include "model/mcdmodel.h"
#include "graphic/entity.h"
#include "command/addentitycommand.h"
#include "command/addassociationcommand.h"

// Qt
#include <QGraphicsSceneMouseEvent>
#include <QUndoStack>
#include <QUndoCommand>
#include <QGraphicsScene>

using namespace Model;
using namespace Command;

McdController::McdController(McdModel *model, QGraphicsScene *scene)
    : m_model(model)
    , m_scene(scene)
    , m_undoStack(new QUndoStack(this))
{
}

void McdController::viewClicked(qreal x, qreal y) const {

    // Enregistre les entités cliqué pour pouvoir les lié
    // avec 2 appels de cet fonction
    static QList<Logic::Entity*> clickedEntities;

    switch(m_clickAction) {
    case AddEntity:
        createEntity(x, y);
        break;
    case AddAssociation: {
        auto clickedItem = m_scene->itemAt(x,y, QTransform());
        auto gEnt = dynamic_cast<Graphic::Entity*>(clickedItem);
        if(gEnt != nullptr) {
            clickedEntities << gEnt->entity() ;
            if(clickedEntities.count() >= 2) {
                createAssociation(clickedEntities[0], clickedEntities[1]);
                clickedEntities.clear();
            }
        }
        break;
    }
    case Inheritence: {
        /*
         auto clickedItem = m_scene->itemAt(x,y, QTransform());
         auto gEnt = dynamic_cast<Graphic::Entity*>(clickedItem);
        if(gEnt != nullptr) {
            clickedEntities << gEnt->entity() ;
            if(clickedEntities.count() >= 2) {
                createInheritence(clickedEntities[0], clickedEntities[1]);
                clickedEntities.clear();
            }
        }*/
        break;
    }
    }
}

void McdController::createEntity(qreal x, qreal y) const {
    m_undoStack->push(new AddEntityCommand(x, y, m_model, m_scene ));
}

void McdController::createAssociation (
        Logic::Entity *entity1,
        Logic::Entity *entity2
        ) const
{
    auto cmd = new AddAssociationCommand(entity1, entity2, m_model, m_scene);
    m_undoStack->push(cmd);
}

void McdController::setClickAction(ClickAction action) {
    m_clickAction = action;
}

McdController::ClickAction McdController::clickAction() const {
    return m_clickAction;
}

QGraphicsScene* McdController::scene() const {
    return m_scene;
}

Model::McdModel* McdController::model() const {
    return m_model;
}

void McdController::setModel(McdModel *model) {
    m_model = model;
}

void McdController::setScene(QGraphicsScene* scene) {
    m_scene = scene;
}
