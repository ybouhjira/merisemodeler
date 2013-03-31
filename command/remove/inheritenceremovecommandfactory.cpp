#include "inheritenceremovecommandfactory.h"
#include "graphic/inheritencearrowobject.h"

using namespace Command;

InheritenceRemoveCommand* InheritenceRemoveCommandFactory::create(
        Graphic::Object *object,
        Model::McdModel *model,
        QGraphicsScene *scene)
{
    return new InheritenceRemoveCommand(
                static_cast<Graphic::InheritenceArrowObject*>(object),
                model,
                scene);
}

