#ifndef MCDUI_H
#define MCDUI_H

#include <ModelUi.h>


/**
 * @brief The McdUi class
 */
class McdUi : public ModelUi
{

// METHODES ====================================================================
public:
    explicit McdUi(QWidget *parent = 0);

// ATTRIBUTS ===================================================================
private:
    QAction
        *m_addEntityAction,
        *m_addAssociationAction,
        *m_addInheritanceAction;

};

#endif // MCDUI_H
