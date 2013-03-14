#include "entityeditwidget.h"
#include "entity.h"

// Qt
#include <QLineEdit>
#include <QVBoxLayout>
#include <QTableView>
#include <QTabWidget>
#include <QFormLayout>
#include <QRegExpValidator>

EntityEditWidget::EntityEditWidget(Entity *entity, QWidget *parent)
    : QWidget(parent)
    , m_entity(entity)
    , m_entityPageWidget(new QWidget)
    , m_tabWidget(new QTabWidget)
    , m_nameLineEdit(new QLineEdit)
    , m_propertiesView(new QTableView)
{
    setLayout(new QVBoxLayout);
    layout()->addWidget(m_tabWidget);
    m_tabWidget->addTab(m_entityPageWidget,tr("Entity"));

    // Page entité
    QVBoxLayout *page1Layout = new QVBoxLayout(m_entityPageWidget) ;
    // Nom : [        ]
    QFormLayout *nameLayout = new QFormLayout;
    page1Layout->addLayout(nameLayout);
    nameLayout->addRow(tr("Name : "), m_nameLineEdit);
    auto validr = new QRegExpValidator(QRegExp("^[a-zA-Z_][a-zA-Z0-9_]*$"));
    m_nameLineEdit->setValidator(validr);

    // Table des propriétés
    page1Layout->addWidget(m_propertiesView);

    // Connections
    connect(m_nameLineEdit, &QLineEdit::textChanged, [=](QString const& text) {
        m_entity->setName(text);
        emit entityEdited(m_entity);
    });
}

void EntityEditWidget::setEntity(Entity *entity) {
    if(entity != m_entity) {
        m_entity = entity ;
        emit entityChanged(m_entity);

        // Mettre à jour l'affichage
        m_nameLineEdit->setText(entity->name());
    }
}

Entity* EntityEditWidget::entity() const {
    return m_entity;
}
