#ifndef MCDGRAPHICSSCENECOMMAND_H
#define MCDGRAPHICSSCENECOMMAND_H

#include "namespace.h"
#include "model/namespace.h"
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
            Model::McdModel* mcd,
            QString const& text = "",
            QUndoCommand* parent = nullptr);

    /**
     * @brief Destructeur
     */
    virtual ~McdCommand();

    /**
     * @brief Accesseur
     * @return Le MCD
     */
    Model::McdModel* mcd() const;

    // Redéfinitions
    /**
     * @brief m_applied = false et appelle QUndoCommand::undo()
     */
    void undo();

    /**
     * @brief m_applied = true et appelle QUndoCommand::redo()
     */
    void redo();

    // Accesseurs et mutateurs
    /**
     * @brief Mutateur
     */
    void setApplied(bool applied);

    /**
     * @brief Accesseur
     */
    bool isApplied() const;

    // ATTRIBUTS
private:
    /**
     * @brief La scene sur laquelle doit etre appliqué la commande
     */
    Model::McdModel* m_mcd;

    /**
     * @brief Indique que la commande est appliqué sur le modèle, ça veut
     * dire que m_applied apprés l'appel de undo()
     */
    bool m_applied;
};

#endif // MCDGRAPHICSSCENECOMMAND_H
