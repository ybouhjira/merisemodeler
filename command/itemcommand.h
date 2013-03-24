#ifndef ADDITEMCOMMAND_H
#define ADDITEMCOMMAND_H

#include "mcdcommand.h"
#include "namespace.h"
#include "model/namespace.h"
#include "logic/namespace.h"

// Qt
class QGraphicsScene;

/**
 * @brief Command d'ajout d'un élément à l'MCD
 */
class Command::ItemCommand : public Command::McdCommand
{
    // METHODES
protected:
    /**
     * @brief Constructeur
     */
    explicit ItemCommand(
            Model::McdModel* mcd,
            QGraphicsScene* scene,
            QString const& text,
            QUndoCommand* parent = nullptr
            );

    /**
     * @brief Accesseur
     */
    QGraphicsScene* scene() const;

public:
    /**
     * @brief Destructeur
     */
    virtual ~ItemCommand();

    //ATTRIBUTS
private:
    /**
     * @brief QGraphicsScene dans la quelle la commande doit ajouter un
     * Graphic::Item
     */
    QGraphicsScene* m_scene;

};

#endif // ADDITEMCOMMAND_H
