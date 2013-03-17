#include "comboboxdelegate.h"
#include "logic/typefactory.h"

#include <QComboBox>
#include <QPainter>

using namespace Ui;

ComboBoxDelegate::ComboBoxDelegate(QObject *parent) :
    QStyledItemDelegate(parent)
{
    for(QString item : Logic::TypeFactory::meriseTypes())
        m_items.append(item);
}

QWidget* ComboBoxDelegate::createEditor (
        QWidget *parent,
        const QStyleOptionViewItem &,
        const QModelIndex &) const
{
    auto editor = new QComboBox(parent);
    editor->setEditable(true);
    for(QString item : m_items)
        editor->addItem(item);
    return editor;
}

void ComboBoxDelegate::setEditorData(
        QWidget *editor,
        const QModelIndex &index) const
{
    QString cellText = index.data().toString();
    auto comboBox = static_cast<QComboBox*>(editor);
    comboBox->setCurrentIndex(m_items.indexOf(cellText));
}
