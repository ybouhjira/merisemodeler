#ifndef MCDCONTROLLER_H
#define MCDCONTROLLER_H

#include "namespace.h"
#include "mcdmodel.h"
#include "graphic/style.h"

class QGraphicsSceneMouseEvent;
class QUndoStack;
class QGraphicsScene;

/**
 * @brief McdController est un controlleur utilisé
 * pour controler Model::McdModel
 */
class Model::McdController : public QObject
{
    Q_OBJECT
    // TYPES
public:
    /**
     * @brief Définit l'action effectué lors d'un clique
     */
    enum ClickAction {
        AddEntity,       //! Ajout d'une entité
        AddAssociation,  //! Ajout d'une association
        Inheritence,     //! Ajout d'une relation d'héritage entre deux entité
        Remove,          //! Supression
        Select           //! Selection si on clique sur un élément
    };

    // METHODES
public:
    /**
     * @brief Constructeur
     */
    McdController(Model::McdModel *model, QGraphicsScene *scene);

    /**
     * @brief Accesseur
     */
    ClickAction clickAction() const;

    // Accesseurs
    /**
     * @brief Accesseur
     */
    Model::McdModel* model() const;

    /**
     * @brief Accesseur
     */
    QGraphicsScene* scene() const;

public slots:
    /**
     * @brief Mutateur
     */
    void setClickAction(ClickAction action) ;

    /**
     * @brief Gére le clique de Model::McdScene
     */
    void viewClicked(qreal x, qreal y) const ;

    // Mutateurs
    /**
     * @brief Mutateur
     */
    void setModel(Model::McdModel* model);

    /**
     * @brief Mutateur
     */
    void setScene(QGraphicsScene* scene);

    /**
     * @brief Undo
     **/
    void undo();

    /**
     * @brief Redo
     */
    void redo();

    /**
     * @return La pile de commande
     */
    QUndoStack* stack();

    /**
     * @brief ApplyStyle
     * @param style
     */
    void ApplyStyle(Graphic::Style* style);

    // ATTRIBUTS
private:
    /**
     * @brief Le modèle MCD
     */
    Model::McdModel *m_model;

    /**
     * @brief Scène reprèsentant le Modèle MCD
     */
    QGraphicsScene *m_scene;

    /**
     * @brief Pile des commandes de type QUndoCommand
     */
    QUndoStack *m_stack;

    /**
     * @brief m_clickAction
     */
    ClickAction m_clickAction;
};

#endif // MCDCONTROLLER_H
