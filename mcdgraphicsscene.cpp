#include "mcdgraphicsscene.h"

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
