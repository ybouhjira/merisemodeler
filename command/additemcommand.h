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

public:
    /**
     * @brief Destructeur
     */
    virtual ~AddItemCommand();

    /**
     * @return Retourne l'element ajouté
     */
    virtual Logic::Item* item() const = 0;

    // Accesseurs
    /**
     * @brief Accesseur
     */
    qreal x() const ;

    /**
     * @brief Accesseur
     */
    qreal y() const ;

protected:
    // Mutateur
    /**
     * @brief Mutateur
     */
    void setX(qreal x) ;

    /**
     * @brief Mutateur
     */
    void setY(qreal y);

private:
    /**
     * @brief Ordonnée
     */
    qreal m_x;

    /**
     * @brief Abssice
     */
    qreal m_y;
};

#endif // ADDITEMCOMMAND_H
