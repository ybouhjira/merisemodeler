
#include "mcdmodel.h"

#include "logic/entity.h"
#include "mcdgraphicsscene.h"

#include "graphic/style.h"
#include "graphic/entity.h"
#include "graphic/association.h"
#include "graphic/inheritencearrowobject.h"

// Qt
#include <QGraphicsSceneMouseEvent>

McdGraphicsScene::McdGraphicsScene(McdModel *mcd)
    : QGraphicsScene((QObject*)mcd)
    , m_mcd(mcd)
    , m_mode(None)
{
}

McdGraphicsScene::~McdGraphicsScene() {
}

McdGraphicsScene::Mode McdGraphicsScene::mode() const {
    return m_mode;
}

void McdGraphicsScene::setMode(Mode const& mode) {
    m_mode = mode ;
}

void McdGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    // position de la souris dans la QGraphicsScene
    qreal x = event->scenePos().x();
    qreal y = event->scenePos().y();

    // AJOUTER UNE ENTITE
    if(m_mode == AddEntity) {
        Logic::Entity *entity = m_mcd->createEntity();
        addItem(new Graphic::Entity(entity, x, y));
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
                Logic::Association *assoc = m_mcd->createAssociation(entity1, entity2);

                // Ajout l'association au centre
                Graphic::Entity* gEnt1 = entity1->graphicObject();
                Graphic::Entity* gEnt2 = entity2->graphicObject();
                qreal assocX = (gEnt1->x() + gEnt2->x()) / 2 ;
                qreal assocY = (gEnt1->y() + gEnt2->y()) / 2 ;
                auto gAssoc = new Graphic::Association(assoc, assocX, assocY);
                addItem(gAssoc);

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
