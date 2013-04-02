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
    , m_stack(new QUndoStack(this))
{
}

void McdController::viewClicked(qreal x, qreal y) const {
    // Save the entities to link, between method calls
    static QList<Logic::Entity*> entsToLink;

    switch(m_clickAction) {
    case AddEntity:
        m_stack->push(new AddEntityCommand(x, y, m_model, m_scene ));
        break;
    case AddAssociation: {
        auto clickedGraphicEntity = dynamic_cast<Graphic::Entity*>(m_scene->itemAt(x,y, QTransform()));
        if (clickedGraphicEntity != nullptr) {
            entsToLink << clickedGraphicEntity->entity() ;
            if (entsToLink.count() >= 2) {
                m_stack->push(new AddAssociationCommand(entsToLink[0], entsToLink[1], m_model, m_scene));
                entsToLink.clear();
            }
        }
        break;
    }
    case Inheritence: {
        // TODO : add InheritenceLink
        break;
    }

    }
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


void McdController::undo() {
    m_stack->undo();
}

void McdController::redo() {
    m_stack->redo();
}

QUndoStack* McdController::stack() {
    return m_stack;
}
