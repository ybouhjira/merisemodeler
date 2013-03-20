#ifndef ADDITEMCOMMAND_H
#define ADDITEMCOMMAND_H

#include "mcdcommand.h"
#include "namespace.h"
#include "logic/namespace.h"

// Qt
#include <QUndoCommand>

/**
 * @brief Command d'ajout d'un élément à l'MCD
 */
class Command::AddItemCommand : public Command::McdCommand
{
    // METHODES
protected:
    /**
     * @brief Constructeur
     */
    explicit AddItemCommand(
            Ui::McdModel* mcd,
            QString const& text,
            QUndoCommand* parent = nullptr
            );

    /**
     * @brief Destructeur
     */
    virtual ~AddItemCommand();
    
public:
    /**
     * @return Retourne l'element ajouté
     */
    virtual Logic::Item* item() const = 0;
};

#endif // ADDITEMCOMMAND_H
