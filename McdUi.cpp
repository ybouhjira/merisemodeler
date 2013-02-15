#include "McdUi.h"

// Qt
#include <QToolBar>
#include <QAction>

McdUi::McdUi(QWidget *parent)
    : ModelUi(parent)
    , m_addEntityAction(new QAction(QIcon(":/entity"),"Entité",this))
    , m_addAssociationAction(new QAction(QIcon(":/assoc"),"Association",this))
    , m_addInheritanceAction(new QAction(QIcon(":/inherit"),"Héritage",this))
{
    m_toolBar->addAction(m_addEntityAction);
    m_toolBar->addAction(m_addAssociationAction);
    m_toolBar->addSeparator();
    m_toolBar->addAction(m_addInheritanceAction);
}
