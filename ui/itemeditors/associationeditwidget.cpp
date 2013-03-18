#include "associationeditwidget.h"
#include "logic/property.h"
#include "logic/typefactory.h"
#include "associationtablemodel.h"

// Qt
#include <QFormLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QTabWidget>
#include <QTableView>
#include <QLineEdit>

using namespace Ui;
AssociationEditWidget::AssociationEditWidget(Logic::Association *assoc ,
                                             QWidget* parent)
    : ItemEditWidget(parent)
    , m_tableModel(new AssociationTableModel(assoc, this))
    , m_page1Widget(new QWidget)
    , m_page2Widget(new QWidget)
    , m_tabWidget(new QTabWidget)
    , m_addButton(new QPushButton(tr("Add")))
    , m_removeButton(new QPushButton(tr("Remove")))
    , m_tableView(new QTableView)
{
    setAssociation(assoc);
    setLayout(new QHBoxLayout);
    layout()->addWidget(m_tabWidget);

    // tabWidget
    m_tabWidget->addTab(m_page1Widget, tr("Association"));
    m_tabWidget->addTab(m_page2Widget, tr("Cardinalities"));

    // ONGLET ASSOCIATION
    // ==========================
    auto page1Layout = new QVBoxLayout;
    m_page1Widget->setLayout(page1Layout);

    // Layout horizontal pour la case de nom et boutons
    auto hLayout = new QHBoxLayout;
    page1Layout->addLayout(hLayout);
    // nom
    auto fLayout = new QFormLayout;
    fLayout->addRow(tr("Name"), nameLineEdit());
    hLayout->addLayout(fLayout);
    // boutons
    hLayout->addWidget(m_addButton);
    hLayout->addWidget(m_removeButton);

    // table des propriétés
    m_page1Widget->layout()->addWidget(m_tableView);
    m_tableView->setModel(m_tableModel);

    // ONGLET CARDINALITES
    // ==========================
    auto cardLayout = new QFormLayout(m_page2Widget);
    // TODO %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

    // CONNECTIONS
    //============
    connect(m_addButton, SIGNAL(clicked()), this, SLOT(addProperty()) );
    connect(m_removeButton, SIGNAL(clicked()),
            this, SLOT(removeSelectedProperties()));

    // update
    connect(m_tableModel, SIGNAL(dataChanged(QModelIndex,QModelIndex)),
            this, SIGNAL(itemEdited()) );
}

Logic::Association* AssociationEditWidget::item() const {
    return m_association;
}

void AssociationEditWidget::addProperty() {
    m_tableModel->addProperty(new Logic::Property(
                                  "property",
                                  Logic::TypeFactory().buildType()));
    emit itemEdited();
}

void AssociationEditWidget::removeSelectedProperties() {
    qWarning("Not yet implemented");
}

Ui::AssociationTableModel* AssociationEditWidget::propertiesModel() const {
    return m_tableModel;
}

void AssociationEditWidget::setAssociation(Logic::Association *assoc) {
    if(assoc != m_association ) {
        m_association = assoc;

        // lineedit
        if(assoc != nullptr) {
            emit itemChanged();
            nameLineEdit()->setText(assoc->name());
            m_tableModel->setAssociation(assoc);
        }
    }
}
