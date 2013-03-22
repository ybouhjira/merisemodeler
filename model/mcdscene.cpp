#include "mcdmodel.h"

#include "logic/entity.h"
#include "mcdscene.h"

#include "graphic/style.h"
#include "graphic/entity.h"
#include "graphic/association.h"
#include "graphic/inheritencearrowobject.h"

#include "command/addentitycommand.h"
#include "command/addassociationcommand.h"

// Qt
#include <QGraphicsSceneMouseEvent>
#include <QUndoStack>

using namespace Model;

McdScene::McdScene(McdModel *mcd)
    : QGraphicsScene((QObject*)mcd)
    , m_mcd(mcd)
    , m_mode(None)
    , m_undoStack(new QUndoStack(this))
{
}

McdScene::~McdScene() {
}

McdScene::Mode McdScene::mode() const {
    return m_mode;
}

void McdScene::setMode(Mode const& mode) {
    m_mode = mode ;
}

void McdScene::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    // position de la souris dans la QGraphicsScene
    qreal x = event->scenePos().x();
    qreal y = event->scenePos().y();


    // AJOUTER UNE ENTITE
    if(m_mode == AddEntity) {
        auto cmd = new Command::AddEntityCommand(x, y, m_mcd);
        m_undoStack->push(cmd);
        setMode(None);
    }// AJOUTER UNE ASSOCIATION
    else if(m_mode == AddAssociation) {
        QGraphicsItem *clickedItem = itemAt(x,y, QTransform());
        auto *clickedEntity = dynamic_cast<Graphic::Entity*>(clickedItem);

        if(clickedEntity != nullptr) {
            static Logic::Entity *entity1 = nullptr;

            // Clique sur la premier entité
            if (entity1 == nullptr) {
                entity1 = clickedEntity->entity();
            }// Clique sur la seconde entité
            else {
                Logic::Entity *entity2 = clickedEntity->entity();
                auto cmd = new Command::AddAssociationCommand(entity1, entity2, m_mcd);
                m_undoStack->push(cmd);

                // Clean up
                entity1 = nullptr;
                setMode(None);
            }
        }
    }// HERITAGE
    else if(m_mode == Inheritence) {
        // !! COPIER COLLER !!
        QGraphicsItem *clickedItem = itemAt(x,y, QTransform());
        auto *clickedEntity = dynamic_cast<Graphic::Entity*>(clickedItem);

        if(clickedEntity != nullptr) {
            static Logic::Entity *entity1 = nullptr;

            // Clique sur la premier entité
            if (entity1 == nullptr) {
                entity1 = clickedEntity->entity();
            }// Clique sur la seconde entité
            else {
                Logic::Entity *entity2 = clickedEntity->entity();
                entity1->addParent(entity2);

                // Ajout de la fléche d'héritage
                auto arrow = new Graphic::InheritenceArrowObject(
                            entity1->graphicObject(),
                            entity2->graphicObject()
                            );
                addItem(arrow);

                // Clean up
                entity1 = nullptr;
                setMode(None);
            }
        }

    // PASSER L'EVENEMENT
    } else if(m_mode == None) {
        QGraphicsItem* clickedItem = itemAt(x,y, QTransform());
        if(clickedItem != nullptr)
            clickedItem->setSelected(true);
        QGraphicsScene::mousePressEvent(event);
    }
}
