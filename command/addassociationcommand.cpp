#include "addassociationcommand.h"
#include "graphic/association.h"
#include "logic/association.h"
#include "logic/entity.h"
#include "model/mcdmodel.h"

#include <QGraphicsScene>

using namespace Command;

AddAssociationCommand::AddAssociationCommand(
        Logic::Entity *entity1,
        Logic::Entity *entity2,
        Model::McdModel* mcd,
        QGraphicsScene* scene,
        QUndoCommand* parent)
    : ItemCommand(mcd, scene, QObject::tr("Added an association"), parent)
{
    // Recherche de nom similaire
    // si trouvé => modifier nameSuffix
    QString assocName = QObject::tr("Association");
    QString nameSuffix = "";
    QListIterator<Logic::Item*> iterator(this->mcd()->items());
    while(iterator.hasNext()) {
        while(iterator.hasNext()) {
            if(iterator.next()->name()  == assocName + nameSuffix) {
                nameSuffix = QString::number(nameSuffix.toInt() + 1);
                iterator.toFront();
                break;
            }
        }
    }

    // LOGIC
    QString name = assocName + nameSuffix ;
    m_association = new Logic::Association(name, entity1, entity2);

    // GRAPHIC
    Graphic::Entity *graphicEntity1 = entity1->graphicObject();
    Graphic::Entity *graphicEntity2 = entity2->graphicObject();
    m_association->setGraphicObject (
                new Graphic::Association (
                    m_association,
                    (graphicEntity1->x() + graphicEntity2->x()) / 2,
                    (graphicEntity1->y() + graphicEntity2->y()) / 2
                    )
                );
}

AddAssociationCommand::~AddAssociationCommand() {
    if(!isApplied()) {
        delete m_association->graphicObject();
        delete m_association;
    }
}

void AddAssociationCommand::undo() {
    ItemCommand::undo();
    scene()->removeItem(m_association->graphicObject());
    mcd()->removeItem(m_association);
}

void AddAssociationCommand::redo() {
    ItemCommand::redo();
    mcd()->addItem(m_association);
    scene()->addItem(m_association->graphicObject());
}
