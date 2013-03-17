#include "entityeditwidget.h"
#include "logic/entity.h"
#include "entitytablemodel.h"
#include "comboboxdelegate.h"
#include "logic/typefactory.h"

// Qt
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTableView>
#include <QTabWidget>
#include <QFormLayout>
#include <QPushButton>

using namespace Ui;

EntityEditWidget::EntityEditWidget(Logic::Entity *entity, QWidget *parent)
    : ItemEditWidget(parent)
    , m_entity(entity)
    , m_entityPageWidget(new QWidget)
    , m_tabWidget(new QTabWidget)
    , m_tableView(new QTableView)
    , m_tableModel(new EntityTableModel(m_entity, this))
    , m_addButton(new QPushButton(tr("Add")))
    , m_removeButton(new QPushButton(tr("Remove")))
{
    setLayout(new QVBoxLayout);
    layout()->addWidget(m_tabWidget);
    m_tabWidget->addTab(m_entityPageWidget,tr("Entity"));

    // Page entité
    auto page1Layout = new QVBoxLayout(m_entityPageWidget) ;
    auto horzlayout = new QHBoxLayout;
    page1Layout->addLayout(horzlayout);

    // Case Nom
    QFormLayout *nameLayout = new QFormLayout;
    nameLayout->addRow(tr("Name"), nameLineEdit());
    horzlayout->addLayout(nameLayout);

    // Boutons ajouter & supprimer
    horzlayout->addWidget(m_addButton);
    horzlayout->addWidget(m_removeButton);

    // Table des propriétés
    page1Layout->addWidget(m_tableView);
    m_tableView->setModel(m_tableModel);
    m_tableView->setItemDelegateForColumn(1, new ComboBoxDelegate(m_tableView));

    // Connections
    // Bouton ajouter
    connect(m_addButton, SIGNAL(clicked()), this, SLOT(addProperty()) );

    // connection avec le model
    connect(propertiesModel(), &QAbstractItemModel::dataChanged,
            this, &ItemEditWidget::itemEdited);
}

void EntityEditWidget::setEntity(Logic::Entity *entity) {
    if(entity != m_entity) {
        m_entity = entity ;
        emit itemChanged();

        // Mettre à jour l'affichage
        m_tableModel->setEntity(entity);
    }
}

Logic::Entity* EntityEditWidget::item() const {
    return m_entity;
}

void EntityEditWidget::addProperty() {
    m_tableModel->addProperty(
                new Logic::Property(tr("property"),
                                    Logic::TypeFactory().buildType()));
    emit itemEdited();
}

EntityTableModel* EntityEditWidget::propertiesModel() const {
    return m_tableModel;
}

void EntityEditWidget::removeSelectedProperties() {
    qWarning("EntityEditWidget::removeSelectedProperties() not yet implemented");
}
