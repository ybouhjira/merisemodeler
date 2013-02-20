#ifndef MCDUI_H
#define MCDUI_H

#include <modelui.h>

/**
 * @brief The McdUi class
 */
class McdUi : public ModelUi
{

    // METHODES
public:
    /**
     * @brief Constructeur
     * @param parent Widget parent
     */
    explicit McdUi(QWidget *parent = 0);

    // ATTRIBUTS
private:
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
