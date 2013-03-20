#ifndef MCDGRAPHICSSCENECOMMAND_H
#define MCDGRAPHICSSCENECOMMAND_H

#include "namespace.h"
#include "ui/namespace.h"
#include <QUndoCommand>

/**
 * @brief La classe McdGraphicsSceneCommand représente une command qui modifie
 * un modèle MCD et peut etre annulée ou refaite
 */
class Command::McdCommand : public QUndoCommand
{
    // METHODES
public:
    /**
     * @brief Constructeur
     * @param mcd Le modèle MCD sur lequel appliquer la commande
     * @param text Un texte descriptif de la commande
     * @param parent Commande mère
     */
    explicit McdCommand(
            Ui::McdModel* mcd,
            QString const& text,
            QUndoCommand* parent = nullptr);

    /**
     * @brief Destructeur
     */
    virtual ~McdCommand();

    /**
     * @brief Accesseur
     * @return Le MCD
     */
    Ui::McdModel* mcd() const;

    // ATTRIBUTS
private:
    /**
     * @brief La scene sur laquelle doit etre appliqué la commande
     */
    Ui::McdModel* m_mcd;
};

#endif // MCDGRAPHICSSCENECOMMAND_H
