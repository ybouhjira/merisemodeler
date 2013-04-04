#ifndef REMOVEENTITYCOMMAND_H
#define REMOVEENTITYCOMMAND_H

#include "command/remove/abstractremovecommand.h"
#include "logic/namespace.h"
#include "graphic/namespace.h"

class Command::EntityRemoveCommand : public Command::AbstractRemoveCommand
{
public:
    /**
     * @brief Constructeur
     * @param model Modèle MCD
     * @param scene Scene graphique
     * @param parent Commande mère
     */
    EntityRemoveCommand(
            Logic::Entity *entity,
            Model::McdModel* model,
            QGraphicsScene* scene,
            QUndoCommand *parent = nullptr);

    /**
     * @brief Destructeur
     */
    virtual ~EntityRemoveCommand();

    void undo();

    void redo();

private:
    class Logic::Entity* m_entity;
};

#endif // REMOVEENTITYCOMMAND_H
