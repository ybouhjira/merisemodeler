#ifndef MCDUI_H
#define MCDUI_H

#include "modelui.h"
class McdModel;
class ItemsBuilder;

/**
 * @brief L'interface graphique du MCD
 */
class McdUi : public ModelUi
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
    McdModel* model() const ;

public slots:
    /**
     * @brief Mutateur
     * @param mcd Model MCD
     */
    void setModel(McdModel* mcd) ;

signals:
    void modelChanged(McdModel*) ;
private:
    /**
     * @brief Constructeur
     * @param parent Widget parent
     */
    explicit McdUi(QWidget *parent = 0);

    // ATTRIBUTS
private:
    // static
    static McdUi* m_instance;

    // non static
    /**
     * @brief le MCD
     */
    McdModel *m_model;

    /**
     * @brief QAction qui ajoute une entité
     */
    QAction *m_addEntityAction;

    /**
      * @brief QAction qui ajoute une Associations
      */
    QAction *m_addAssociationAction;

    /**
      * @brief QAction qui Ajoute un relation d'hériatge entre deux entités
      */
    QAction *m_addInheritanceAction;

};

#endif // MCDUI_H
