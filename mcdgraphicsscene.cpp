#include "mcdgraphicsscene.h"
#include "graphicentity.h"
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
    qreal x = event->scenePos().x();
    qreal y = event->scenePos().y();

    if(m_mode == AddEntity) {
        Entity *entity = m_mcd->createNewEntity();
        addItem(new GraphicEntity(entity, x, y));
    }else if(m_mode == None) {
        QGraphicsScene::mousePressEvent(event);
    }

    setMode(None);
}
