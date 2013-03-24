#ifndef MCDUI_H
#define MCDUI_H

#include "namespace.h"
#include "model/namespace.h"
#include "modelui.h"

// Qt
class QGraphicsScene;
class QActionGroup;

/**
 * @brief L'interface graphique du MCD
 */
class Ui::McdUi : public Ui::ModelUi
{
    Q_OBJECT
    // METHODES
public:
    /**
     * @brief Retourne l'instance unique de cette classe, si cette instance
     * n'existe pas elle sera creée
     */
    static McdUi* getInstance();

    /**
     * @brief Accesseur
     * @return MCD actuel
     */
    Model::McdModel* model() const ;

public slots:
    /**
     * @brief Mutateur
     * @param mcd Model MCD
     */
    void setModel(Model::McdModel* mcd, QGraphicsScene *scene) ;

private slots:
    /**
     * @brief Appelé lorsque le bouton MOve est cliqué
     */
    void setMoveClickAction() const;

    /**
     * @brief setRemoveClickAction
     */
    void setRemoveClickAction() const;

    /**
     * @brief Appelé lorsque le bouton Entity est cliqué
     */
    void setAddEntityClickAction() const ;

    /**
     * @brief Appelé lorsque le bouton Association est cliqué
     */
    void setAddAssociationClickAction() const ;

    /**
     * @brief Appelé lorsque le bouton Association est cliqué
     */
    void setInheritencClickAction() const;

    /**
     * @brief Change l'element affiché dans le panneau selon la selection
     */
    void sceneSelectionChanged();

signals:
    /**
     * @reimp
     * @brief Model Changé avec McdUi::setModel
     */
    void modelChanged(Model::McdModel*) ;

private:
    /**
     * @brief Constructeur
     * @param parent Widget parent
     */
    explicit McdUi(QWidget *parent = 0);

    // ATTRIBUTS
private:
    // static
    static Ui::McdUi* m_instance;

    // non static
    /**
     * @brief le MCD
     */
    Model::McdModel *m_model;

    /**
     * @brief La representation du modéle MCD
     */
    QGraphicsScene *m_scene;

    /**
     * @brief Controleur
     */
    Model::McdController* m_controller;

    /**
     * @brief Groupe les objets de type QAction
     */
    QActionGroup *m_actionGroup;

    QAction
    *m_moveAction,      //!< @brief Déplacement
    *m_removeAction,    //! @brief Suppression
    *m_entityAction,    //!< @brief Ajoute une entité
    *m_assocAction,     //!< @brief Ajoute une association
    *m_inheritAction;    //!< @brief Ahoute une héritage

    /**
     * @brief Widget qui edite l'entité
     */
    Ui::EntityEditWidget *m_entityWidget;

    /**
     * @brief Widget qui edite l'association
     */
    Ui::AssociationEditWidget *m_associationWidget;

    /**
     * @brief Panneau qui contient les widgets qui permettent
     * d'éditer les entités et associaotions
     */
    QDockWidget *m_itemEditDock;

};

#endif // MCDUI_H
