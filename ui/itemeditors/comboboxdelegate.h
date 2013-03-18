#ifndef COMBOBOXDELEGATE_H
#define COMBOBOXDELEGATE_H

#include "ui/namespace.h"

// Qt
#include <QStyledItemDelegate>

class Ui::ComboBoxDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit ComboBoxDelegate(QObject *parent = 0);

    /**
     * @reimp
     */
    QWidget* createEditor(QWidget *parent,
                          const QStyleOptionViewItem &option,
                          const QModelIndex &index) const override;

    /**
     * @reimp
     */
    void setEditorData(QWidget *editor,
                       const QModelIndex &index) const override;
    /**
     * @reimp
     *
    void setEditorData(QWidget *editor,
                       const QModelIndex &index) const override;*/

private:
    QStringList m_items;
};

#endif // COMBOBOXDELEGATE_H
