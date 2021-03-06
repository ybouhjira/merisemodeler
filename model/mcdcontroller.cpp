#include "mcdcontroller.h"
#include "model/mcdmodel.h"
#include "graphic/entity.h"

#include "command/addentitycommand.h"
#include "command/addassociationcommand.h"
#include "command/inheritenceaddcommand.h"
#include "command/remove/removecommandfactory.h"
#include "command/remove/abstractremovecommand.h"
#include "command/remove/unsupporteditemexception.h"

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
            if (entsToLink.count() >= 2 && entsToLink[0] != entsToLink[1]) {
                m_stack->push(new AddAssociationCommand(entsToLink[0], entsToLink[1], m_model, m_scene));
                entsToLink.clear();
            }else if(entsToLink.count() >= 2) {
                entsToLink.clear();
            }
        }
        break;
    }
    case Inheritence: {
        auto clickedGraphicEntity = dynamic_cast<Graphic::Entity*>(m_scene->itemAt(x,y, QTransform()));
        if (clickedGraphicEntity != nullptr) {
            entsToLink << clickedGraphicEntity->entity() ;
            if (entsToLink.count() >= 2 && entsToLink[0] != entsToLink[1]) {
                m_stack->push(new InheritenceAddCommand(entsToLink[0], entsToLink[1], m_model, m_scene));
                entsToLink.clear();
            } else if(entsToLink.count() >= 2) {
                entsToLink.clear();
            }
        }
        break;
    } case Remove: {
        try {
            QGraphicsItem* item = m_scene->itemAt(x, y, QTransform());
            if(item == nullptr)
                return;
            RemoveCommandFactory* factory = Command::RemoveCommandFactory::createFactory(item);
            m_stack->push(factory->create(static_cast<Graphic::Object*>(item), m_model, m_scene));
            delete factory;
        } catch(Command::UnsupportedItemException) {

        }
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

void McdController::ApplyStyle(Graphic::Style *style) {
    QList<QGraphicsItem*> items = m_scene->selectedItems();

    for(auto item : items) {
        auto object = dynamic_cast<Graphic::Object*>(item);
        if(object != nullptr)
            object->setStyle(style);
    }
}
