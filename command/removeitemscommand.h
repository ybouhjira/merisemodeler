#ifndef REMOVEITEMCOMMAND_H
#define REMOVEITEMCOMMAND_H

#include "mcdcommand.h"
#include "logic/namespace.h"

// Qt
#include <QList>

/**
 * @brief Commande de  supression d'un ou plusieurs elements
 */
class Command::RemoveItemsCommand : public Command::McdCommand
{
public:
    /**
     * @brief Constructeur
     * @param items Elements à supprimer
     * @param mcd Modèle cible
     * @param parent Commande mère
     */
    RemoveItemsCommand(QList<Logic::Item *> items,
            Model::McdModel* mcd,
            QUndoCommand* parent = nullptr);

    /**
     * @brief Destructeur
     */
    ~RemoveItemsCommand();

    // Redéfinitions
    void undo();

    void redo();

private:
    /**
     * @brief Elements supprimés
     */
    QList<Logic::Item*> m_items;
};

#endif // REMOVEITEMCOMMAND_H
