#ifndef ASSOCIATIONREMOVECOMMANDFACTORY_H
#define ASSOCIATIONREMOVECOMMANDFACTORY_H

#include "removecommandfactory.h"

/**
 * @brief Commande de supression d'une association
 */
class Command::AssociationRemoveCommandFactory : public Command::RemoveCommandFactory
{
public:
    Command::AssociationRemoveCommand* create(
            Graphic::Object *object,
            Model::McdModel *model,
            QGraphicsScene *scene);
};

#endif // ASSOCIATIONREMOVECOMMANDFACTORY_H
