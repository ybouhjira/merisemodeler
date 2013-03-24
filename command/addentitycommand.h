#ifndef ADDENTITYCOMMAND_H
#define ADDENTITYCOMMAND_H

#include "command/itemcommand.h"
#include "logic/namespace.h"
#include "graphic/namespace.h"

class QGraphicsScene;

/**
 * @brief Commande d'ajout d'une entité
 */
class Command::AddEntityCommand : public Command::ItemCommand
{
public:
    /**
     * @brief Constructeur
     * @param mcd modèle cible
     * @param text Texte descriptif
     * @param parent commande mère
     */
    AddEntityCommand(qreal x,
            qreal y,
            Model::McdModel* model,
            QGraphicsScene *scene,
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
