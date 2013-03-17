#include "modelstabwidget.h"
#include "mcdui.h"
#include "mcdmodel.h"

// Qt
#include <QTabBar>
#include <QVBoxLayout>

using namespace Ui;

ModelsTabWidget::ModelsTabWidget(QWidget *parent)
    : QWidget(parent)
    , m_tabBar(new QTabBar(this))
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(m_tabBar, 0, Qt::AlignTop);
    m_tabBar->setTabsClosable(true);

    // Connection
    connect(m_tabBar, SIGNAL(tabCloseRequested(int)),
            this, SLOT(removeModel(int)) );
}

void ModelsTabWidget::addModel(const QString &label, McdModel *model) {
    m_models.append(model);
    if(layout()->count() > 1)
        layout()->removeItem(layout()->itemAt(layout()->count() - 1));

    // Ajout de l'interface
    McdUi* ui = McdUi::getInstance();
    layout()->addWidget(ui);
    ui->setModel(model);

    // Ajout du model dans la liste
    m_models.append(model);
    model->setParent(this);

    // Ajout d'un onglet
    m_tabBar->addTab(label);
}

void ModelsTabWidget::removeModel(int index) {
    qDebug("remove");
    m_models.removeAt(index);
}
