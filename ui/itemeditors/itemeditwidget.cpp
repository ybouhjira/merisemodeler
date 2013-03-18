#include "itemeditwidget.h"
#include "logic/item.h"

// Qt
#include <QLineEdit>
#include <QRegExpValidator>
#include <QAbstractItemModel>

using namespace Ui;

ItemEditWidget::ItemEditWidget(QWidget *parent) :
    QWidget(parent)
  , m_nameLineEdit(new QLineEdit(this))
{
    // Ajouter un validateur à la case de nom :
    auto validr = new QRegExpValidator(QRegExp("^[a-zA-Z_][a-zA-Z0-9_]*$"));
    m_nameLineEdit->setValidator(validr);

    // Connections
    // case de nom
    connect(m_nameLineEdit, &QLineEdit::textChanged, [=](QString const& text) {
        item()->setName(text);
        emit itemEdited();
    });
    connect(this, &ItemEditWidget::itemChanged, [=]() {
        m_nameLineEdit->setText(item()->name());
    });

}

QLineEdit* ItemEditWidget::nameLineEdit() const {
    return m_nameLineEdit;
}
