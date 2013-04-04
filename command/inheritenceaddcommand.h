#ifndef INHERITENCEADDCOMMAND_H
#define INHERITENCEADDCOMMAND_H

#include "itemcommand.h"
#include "graphic/namespace.h"

class Command::InheritenceAddCommand : public Command::ItemCommand
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
    InheritenceAddCommand(
            Logic::Entity* entity1,
            Logic::Entity* entity2,
            Model::McdModel* mcd,
            QGraphicsScene *scene,
            QUndoCommand* parent = nullptr
            );

    ~InheritenceAddCommand();
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
    Graphic::InheritenceArrowObject* m_arrow;

    Logic::Entity *m_entity1, *m_entity2;
    
};

#endif // INHERITENCEADDCOMMAND_H
