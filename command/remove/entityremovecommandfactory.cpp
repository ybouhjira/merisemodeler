#include "entityremovecommandfactory.h"
#include "entityremovecommand.h"
#include "graphic/entity.h"

using namespace Command;

EntityRemoveCommand* EntityRemoveCommandFactory::create(
        Graphic::Object *gObject,
        Model::McdModel *model,
        QGraphicsScene *scene )
{
    return new EntityRemoveCommand(
                static_cast<Graphic::Entity*>(gObject)->entity(),
                model, scene);
}
