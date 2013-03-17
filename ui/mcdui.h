#ifndef MCDUI_H
#define MCDUI_H

#include "namespace.h"
#include "modelui.h"

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
    Ui::McdModel* model() const ;

public slots:
    /**
     * @brief Mutateur
     * @param mcd Model MCD
     */
    void setModel(Ui::McdModel* mcd) ;

private slots:
    /**
     * @brief Appelé lorsque le bouton Entity est cliqué, met la scene en Mode
     * McdModelScene::AddEntity
     */
    void setAddEntityModeOnScene() const ;

    /**
     * @brief Appelé lorsque le bouton Association est cliqué, met la scene
     * en Mode McdModelScene::AddAssociation
     */
    void setAddAssocModeOnScene() const ;

    /**
     * @brief Appelé lorsque le bouton Association est cliqué, met la scene
     * en Mode McdModelScene::Enheritence
     */
    void setInheritenceModeOnScene() const;

    /**
     * @brief Change l'element affiché dans le panneau selon la selection
     */
    void sceneSelectionChanged();

signals:
    /**
     * @reimp
     * @brief Model Changé avec McdUi::setModel
     */
    void modelChanged(Ui::McdModel*) ;

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
    Ui::McdModel *m_model;

    /**
     * @brief QAction qui ajoute une entité
     */
    QAction *m_entityAction;

    /**
      * @brief QAction qui ajoute une Associations
      */
    QAction *m_associationAction;

    /**
      * @brief QAction qui Ajoute un relation d'hériatge entre deux entités
      */
    QAction *m_inheritanceAction;

    /**
     * @brief Widget qui edit l'entité
     */
    Ui::EntityEditWidget *m_entityWidget;

    /**
     * @brief Panneau qui contient les widgets qui permettent
     * d'éditer les entités et associaotions
     */
    QDockWidget *m_itemEditDock;

};

#endif // MCDUI_H
