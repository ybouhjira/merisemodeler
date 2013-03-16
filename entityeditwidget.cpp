#include "entityeditwidget.h"
#include "entity.h"
#include "entitytablemodel.h"

// Qt
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTableView>
#include <QTabWidget>
#include <QFormLayout>
#include <QRegExpValidator>
#include <QPushButton>

EntityEditWidget::EntityEditWidget(Entity *entity, QWidget *parent)
    : QWidget(parent)
    , m_entity(entity)
    , m_entityPageWidget(new QWidget)
    , m_tabWidget(new QTabWidget)
    , m_nameLineEdit(new QLineEdit)
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
    nameLayout->addRow(tr("Name"), m_nameLineEdit);
    auto validr = new QRegExpValidator(QRegExp("^[a-zA-Z_][a-zA-Z0-9_]*$"));
    m_nameLineEdit->setValidator(validr);
    horzlayout->addLayout(nameLayout);

    // Boutons ajouter & supprimer
    horzlayout->addWidget(m_addButton);
    horzlayout->addWidget(m_removeButton);

    // Table des propriétés
    page1Layout->addWidget(m_tableView);
    m_tableView->setModel(m_tableModel);

    // Connections
    // case de nom
    connect(m_nameLineEdit, &QLineEdit::textChanged, [=](QString const& text) {
        m_entity->setName(text);
        emit entityEdited(m_entity);
    });
    // Bouton ajouter
    connect(m_addButton, SIGNAL(clicked()), this, SLOT(addProperty()) );

    // connection avec le model
    connect(m_tableModel, &QAbstractItemModel::dataChanged, [=]() {
        emit entityEdited(m_entity);
    });
}

void EntityEditWidget::setEntity(Entity *entity) {
    if(entity != m_entity) {
        m_entity = entity ;
        emit entityChanged(m_entity);

        // Mettre à jour l'affichage
        m_nameLineEdit->setText(entity->name());
        m_tableModel->setEntity(entity);
    }
}

Entity* EntityEditWidget::entity() const {
    return m_entity;
}

void EntityEditWidget::addProperty() {
    m_tableModel->addProperty(new Property(tr("property"), Type("SomeTYpe")));
    emit entityEdited(m_entity);
}
