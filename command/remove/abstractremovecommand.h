#ifndef ABSTRACTREMOVECOMMAND_H
#define ABSTRACTREMOVECOMMAND_H

#include "../itemcommand.h"
#include "model/namespace.h"

class Command::AbstractRemoveCommand : public Command::ItemCommand
{
public:
    /**
     * @brief Constructeur
     * @param model Modèle MCD
     * @param scene Scene graphique
     * @param parent Commande mère
     */
    AbstractRemoveCommand(
            Model::McdModel* model,
            QGraphicsScene* scene,
            QUndoCommand *parent = nullptr);
};

#endif // ABSTRACTREMOVECOMMAND_H
