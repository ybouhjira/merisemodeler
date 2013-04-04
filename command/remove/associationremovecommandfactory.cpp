#include "associationremovecommandfactory.h"
#include "graphic/association.h"

using namespace Command;

AssociationRemoveCommand* AssociationRemoveCommandFactory::create(
        Graphic::Object *object,
        Model::McdModel *model,
        QGraphicsScene *scene)
{
    return new AssociationRemoveCommand(
                static_cast<Graphic::Association*>(object)->association()
                , model
                , scene);
}
