#ifndef INHERITENCEREMOVECOMMANDFACTORY_H
#define INHERITENCEREMOVECOMMANDFACTORY_H

#include "removecommandfactory.h"
#include "inheritenceremovecommand.h"

class Command::InheritenceRemoveCommandFactory : public Command::RemoveCommandFactory
{
public:
    Command::InheritenceRemoveCommand* create(
            Graphic::Object *object,
            Model::McdModel *model,
            QGraphicsScene *scene );
};

#endif // INHERITENCEREMOVECOMMANDFACTORY_H
