#ifndef ENTITYREMOVECOMMANDFACTORY_H
#define ENTITYREMOVECOMMANDFACTORY_H

#include "removecommandfactory.h"

class Command::EntityRemoveCommandFactory : public Command::RemoveCommandFactory
{
    // METHODES
public:
    Command::EntityRemoveCommand* create(
            Graphic::Object *gObject,
            Model::McdModel *model,
            QGraphicsScene *scene) override;
};

#endif // ENTITYREMOVECOMMANDFACTORY_H
