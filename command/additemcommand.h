#ifndef ADDITEMCOMMAND_H
#define ADDITEMCOMMAND_H

#include "namespace.h"
#include "ui/mcdgraphicsscene.h"
#include <QUndoCommand>

/**
 * @brief Command d'ajout d'un élément
 */
class Command::AddItemCommand : public Command::McdCommand
{
public:
    /**
     * @brief Constructeur
     */
    explicit AddItemCommand(Ui::McdGraphicsScene* scene);
    

};

#endif // ADDITEMCOMMAND_H
