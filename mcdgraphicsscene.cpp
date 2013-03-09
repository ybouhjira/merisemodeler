#include "mcdgraphicsscene.h"
#include "graphicentity.h"
#include "graphicassociation.h"
#include "mcdmodel.h"

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
        Entity *entity = m_mcd->createEntity();
        addItem(new GraphicEntity(entity, x, y));
        setMode(None);
    }// AJOUTER UNE ASSOCIATION
    else if(m_mode == AddAssociation) {
        QGraphicsItem *clickedItem = itemAt(x,y, QTransform());
        auto *clickedEntity = dynamic_cast<GraphicEntity*>(clickedItem);

        if(clickedEntity != nullptr) {
            static Entity *entity1 = nullptr;
            // Clique sur la premier entité
            if (entity1 == nullptr) {
                entity1 = clickedEntity->entity();
            }// Clique sur la seconde entité
            else {
                Entity *entity2 = clickedEntity->entity();
                Association *assoc = m_mcd->createAssociation(entity1, entity2);
                addItem(new GraphicAssociation(assoc,x,y));
                setMode(None);
            }
        }
    }// PASSER L'EVENEMENT
    else if(m_mode == None) {
        QGraphicsScene::mousePressEvent(event);
    }
}
