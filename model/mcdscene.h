#ifndef MCDGRAPHICSSCENE_H
#define MCDGRAPHICSSCENE_H

#include "namespace.h"

// Qt
#include <QGraphicsScene>
class QUndoStack;

/**
 * @brief Cette class est une sous class de QGraphicsScene qui contient
 * les elements graphique representant le MCD comme @ref GraphicEntity, et
 * @ref GraphicAsssociation
 *
 * @todo Refactor to a controller and a View
 */
class Model::McdScene : public QGraphicsScene
{
    Q_OBJECT
    // TYPES
public:
    /**
     * @brief Définit le model actuel de McdGraphicsScene
     */
    enum Mode {
        AddEntity,       //! Mode d'ajout d'une entité
        AddAssociation,  //! Mode d'ajout d'une association
        Inheritence,     //! Mode d'héritage
        Remove,          //! Mode de supression
        None             //! Rien
    };

    // METHODES
public:
    /**
     * @brief Constructeur
     * @param mcd Model MCD à representer
     * @param parent QObject parent qui se charge de la destruction de
     * cet objet
     */
    McdScene(Model::McdModel *mcd = nullptr);

    /**
     * @brief Destructeur
     */
    virtual ~McdScene();

    /**
     * @brief Accesseur
     * @return Mode actuel
     */
    Mode mode() const;

protected:
    /**
     * @reimp
     */
    void mousePressEvent(QGraphicsSceneMouseEvent *event);


public slots:
    /**
     * @brief Mutateur
     * @param mode Mode
     */
    void setMode(Mode const& mode);

    // ATTRIBUTS
private:
    /**
     * @brief Le MCD
     */
    Model::McdModel *m_mcd;

    /**
     * @brief Mode
     */
    Mode m_mode;

    /**
     * @brief Pile des commandes
     */
    QUndoStack *m_undoStack;

};

#endif // MCDGRAPHICSSCENE_H
