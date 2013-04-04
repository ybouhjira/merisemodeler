#ifndef STYLEWIDGET_H
#define STYLEWIDGET_H

#include "ui/namespace.h"
class ColorButton;
class QDoubleSpinBox;

// Qt
#include <QWidget>
class QListView;
class QPushButton;
class QFontComboBox;

class Ui::StyleWidget : public QWidget
{
    Q_OBJECT
public:
    explicit StyleWidget(QWidget *parent = 0);
    
signals:
    
public slots:

private:

    Ui::StyleListModel* m_model;
    QListView *m_listView;
    QPushButton *m_applyButton;
    QFontComboBox *m_fontComboBox;
    ColorButton *m_backgroundColorButton, *m_lineColorButton;
    QDoubleSpinBox *m_spinBox;
};

#endif // STYLEWIDGET_H
