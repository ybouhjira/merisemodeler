#ifndef ADDENTITYCOMMAND_H
#define ADDENTITYCOMMAND_H

#include "additemcommand.h"
#include "logic/namespace.h"

/**
 * @brief Commande d'ajout d'une entité
 */
class Command::AddEntityCommand : public Command::AddItemCommand
{
public:
    /**
     * @brief Constructeur
     * @param mcd modèle cible
     * @param text Texte descriptif
     * @param parent commande mère
     */
    AddEntityCommand(
            qreal x,
            qreal y,
            Ui::McdModel* mcd,
            QUndoCommand* parent = nullptr);

    /**
     * @brief Destructeur
     */
    virtual ~AddEntityCommand();

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
     * @brief L'entité ajoutée
     */
    Logic::Entity* m_entity;
};

#endif // ADDENTITYCOMMAND_H
