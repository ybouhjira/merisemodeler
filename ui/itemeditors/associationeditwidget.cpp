#include "associationeditwidget.h"
#include "logic/property.h"
#include "logic/typefactory.h"
#include "associationtablemodel.h"
#include "logic/entity.h"

// Qt
#include <QFormLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QTabWidget>
#include <QTableView>
#include <QLineEdit>
#include <QComboBox>
#include <QGroupBox>

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
    , m_entity1Box(new QGroupBox)
    , m_entity2Box(new QGroupBox)
    , m_ent1minComboBox(new QComboBox)
    , m_ent1maxComBox(new QComboBox)
    , m_ent2minComboBox(new QComboBox)
    , m_ent2maxComboBox(new QComboBox)
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
    // =========================
    // cardinalites
    m_ent1minComboBox->addItem("0");
    m_ent1minComboBox->addItem("1");
    m_ent2minComboBox->addItem("0");
    m_ent2minComboBox->addItem("1");
    m_ent1maxComBox->addItem("1");
    m_ent1maxComBox->addItem("n");
    m_ent2maxComboBox->addItem("1");
    m_ent2maxComboBox->addItem("n");

    // layout
    auto boxLayout = new QHBoxLayout(m_page2Widget);
    boxLayout->addWidget(m_entity1Box);
    boxLayout->addWidget(m_entity2Box);

    // ent1
    auto ent1FLayout = new QFormLayout;
    m_entity1Box->setLayout(ent1FLayout);
    ent1FLayout->addRow(tr("Min"), m_ent1minComboBox);
    ent1FLayout->addRow(tr("Max"), m_ent1maxComBox);

    // ent2
    auto ent2FLayout = new QFormLayout;
    m_entity2Box->setLayout(ent2FLayout);
    ent2FLayout->addRow(tr("Min"), m_ent2minComboBox);
    ent2FLayout->addRow(tr("Max"), m_ent2maxComboBox);

    // CONNECTIONS
    //============
    connect(m_addButton, SIGNAL(clicked()), this, SLOT(addProperty()) );
    connect(m_removeButton, SIGNAL(clicked()),
            this, SLOT(removeSelectedProperties()));

    // update
    connect(m_tableModel, SIGNAL(dataChanged(QModelIndex,QModelIndex)),
            this, SIGNAL(itemEdited()) );

    // applications des cardinalités
    connect(m_ent1minComboBox, SIGNAL(currentIndexChanged(int)),
            this, SLOT(applyCardinalities()) );
    connect(m_ent1maxComBox, SIGNAL(currentIndexChanged(int)),
            this, SLOT(applyCardinalities()) );

    connect(m_ent2minComboBox, SIGNAL(currentIndexChanged(int)),
            this, SLOT(applyCardinalities()) );
    connect(m_ent2maxComboBox, SIGNAL(currentIndexChanged(int)),
            this, SLOT(applyCardinalities()) );
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
    // Fonction de mise à jour de noms


    if(assoc != m_association ) {
        // Deconnecte l'ancienne association
        if(m_association != nullptr
                && m_association->entity1() != nullptr
                && m_association->entity2() != nullptr
                ) {
            disconnect(m_association->entity1(), &Logic::Item::nameChanged,
                       this, &AssociationEditWidget::updateNames);
            disconnect(m_association->entity2(), &Logic::Item::nameChanged,
                       this, &AssociationEditWidget::updateNames);
        }
        m_association = assoc;

        // lineedit
        if(assoc != nullptr) {
            emit itemChanged();
            nameLineEdit()->setText(assoc->name());
            m_tableModel->setAssociation(assoc);

            // connecte les entités de la nouvelle association avec le slots
            // updatename pour mettre à jour les noms
            updateNames();
            connect(m_association->entity1(), &Logic::Item::nameChanged,
                    this, &AssociationEditWidget::updateNames);
            connect(m_association->entity2(), &Logic::Item::nameChanged,
                    this, &AssociationEditWidget::updateNames);
        }
    }
}

void AssociationEditWidget::updateNames() {
    if(m_association != nullptr
            && m_association->entity1() != nullptr
            && m_association->entity2() != nullptr
            ) {
        m_entity1Box->setTitle(m_association->entity1()->name());
        m_entity2Box->setTitle(m_association->entity2()->name());
    }
}

void AssociationEditWidget::applyCardinalities() {
    if(m_association != nullptr) {
        Logic::Link::Cardinality ent1min, ent1max, ent2min, ent2max;

        ent1min = (m_ent1minComboBox->currentText() == "0")?
                    Logic::Link::Zero : Logic::Link::One;
        ent1max = (m_ent1maxComBox->currentText() == "1")?
                    Logic::Link::One : Logic::Link::N;

        ent2min = (m_ent2minComboBox->currentText() == "0")?
                    Logic::Link::Zero : Logic::Link::One;
        ent2max = (m_ent2maxComboBox->currentText() == "1")?
                    Logic::Link::One : Logic::Link::N;

        m_association->links().first->setMin(ent1min);
        m_association->links().first->setMax(ent1max);

        m_association->links().second->setMin(ent2min);
        m_association->links().second->setMax(ent2max);

        m_association->graphicObject()->updateCardinalities();
    }
}
