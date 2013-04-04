#ifndef STYLEWIDGET_H
#define STYLEWIDGET_H

#include "ui/namespace.h"
#include "graphic/namespace.h"
class ColorButton;

// Qt
#include <QWidget>
class QListView;
class QPushButton;
class QFontComboBox;
class QDoubleSpinBox;

class Ui::StyleWidget : public QWidget
{
    Q_OBJECT
public:
    explicit StyleWidget(QWidget *parent = 0);

signals:
    void styleEdited();

private slots:
    void setBackgroundColor(QColor const& color);

    void setLineColor(QColor const& color);

    void setLineWidth(qreal width);

    // HELPER FUNCTIONS
private:
    Graphic::Style* currentStyle() const;

    // ATTRRIBUTS
private:

    Ui::StyleListModel* m_model;
    QListView *m_listView;
    QPushButton *m_applyButton, *m_addButton, *m_removeButton;
    QFontComboBox *m_fontComboBox;
    ColorButton *m_backgroundColorButton, *m_lineColorButton;
    QDoubleSpinBox *m_spinBox;
};

#endif // STYLEWIDGET_H
