#ifndef INHERITENCEREMOVECOMMAND_H
#define INHERITENCEREMOVECOMMAND_H

#include "command/remove/abstractremovecommand.h"
#include "graphic/namespace.h"

/**
 * @brief Commande de supression d'un relation d'héritage
 */
class Command::InheritenceRemoveCommand : public Command::AbstractRemoveCommand
{
    // METHODES
public:
    /**
     * @brief Constructeur
     * @param arrow Fléche représentant la relation d'héritage
     * @param model modèle MCD
     * @param scene Scène graphique
     * @param parent Commande mère
     */
    InheritenceRemoveCommand(
            Graphic::InheritenceArrowObject* arrow,
            Model::McdModel* model,
            QGraphicsScene* scene,
            QUndoCommand *parent = nullptr
            );

    virtual ~InheritenceRemoveCommand();

    // Redéfinitions
    void undo() ;

    void redo();

    // ATTRIBUTS
private:
    Graphic::InheritenceArrowObject* m_arrow;
};

#endif // INHERITENCEREMOVECOMMAND_H
