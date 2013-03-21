#ifndef ADDASSOCIATIONCOMMAND_H
#define ADDASSOCIATIONCOMMAND_H

#include "additemcommand.h"
#include "logic/association.h"

/**
 * @brief Commande d'ajout d'une association
 */
class Command::AddAssociationCommand : public Command::AddItemCommand
{
    // METHODES
public:
    /**
     * @brief Constructeur
     * @param x Abssice
     * @param y Ordonnée
     * @param mcd Modèle cible
     * @param parent Command mère
     */
    AddAssociationCommand(
            Logic::Entity* entity1,
            Logic::Entity* entity2,
            Ui::McdModel* mcd,
            QUndoCommand* parent = nullptr
            );

    /**
     * @brief Destructeur
     */
    ~AddAssociationCommand();

    // Redéfinitions
    /**
     * @reimp
     */
    void undo();

    /**
     * @reimp
     */
    void redo();

private:

    /**
     * @brief Associatrion ajoutée
     */
    Logic::Association* m_association;
};

#endif // ADDASSOCIATIONCOMMAND_H
