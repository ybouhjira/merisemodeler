#ifndef ASSOCIATIONREMOVECOMMAND_H
#define ASSOCIATIONREMOVECOMMAND_H

#include "abstractremovecommand.h"
#include "logic/namespace.h"

/**
 * @brief Commande de supression d'une association
 */
class Command::AssociationRemoveCommand : public Command::AbstractRemoveCommand
{
    // METHODES
public:
    AssociationRemoveCommand(
            Logic::Association* association,
            Model::McdModel* model,
            QGraphicsScene* scene,
            QUndoCommand *parent = nullptr);

    /**
     * @brief Destructeur
     */
    virtual ~AssociationRemoveCommand();

    // Redefintion

    void undo();

    void redo();

    // ATTRIBUTES
private:
    /**
     * @brief Association supprimée
     */
    Logic::Association* m_association;
};

#endif // ASSOCIATIONREMOVECOMMAND_H
