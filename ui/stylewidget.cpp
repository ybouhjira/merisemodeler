#include "stylewidget.h"
#include "colorbutton.h"
#include "stylelistmodel.h"
#include "graphic/style.h"
// Qt
#include <QListView>
#include <QVBoxLayout>
#include <QPushButton>
#include <QFormLayout>
#include <QFontComboBox>
#include <QDoubleSpinBox>
#include <QHBoxLayout>

using namespace Ui;

StyleWidget::StyleWidget(QWidget *parent) : QWidget(parent)
  , m_model(new StyleListModel)
  , m_listView(new QListView)
  , m_applyButton(new QPushButton(QIcon(":/apply"), tr("Apply")))
  , m_addButton(new QPushButton(QIcon(":/add"), tr("Add")))
  , m_removeButton(new QPushButton(QIcon(":/remove"), tr("Remove")))
  , m_fontComboBox(new QFontComboBox)
  , m_backgroundColorButton(new ColorButton(Qt::white))
  , m_lineColorButton(new ColorButton(Qt::black))
  , m_spinBox(new QDoubleSpinBox)
{
    m_listView->setModel(m_model);

    auto layout = new QVBoxLayout(this);
    layout->addWidget(m_listView);

    // boutons
    auto buttonsLayout = new QHBoxLayout;
    layout->addLayout(buttonsLayout);
    buttonsLayout->addWidget(m_addButton);
    buttonsLayout->addWidget(m_removeButton);
    buttonsLayout->addWidget(m_applyButton);

    auto formLayout = new QFormLayout;
    layout->addLayout(formLayout);
    formLayout->addRow(tr("Font"), m_fontComboBox);
    formLayout->addRow(tr("Background color"), m_backgroundColorButton);
    formLayout->addRow(tr("Line color"), m_lineColorButton);
    formLayout->addRow(tr("Line width"), m_spinBox);
    m_spinBox->setMinimum(0.01);
    m_spinBox->setMaximum(3);

    // CONNECTIONS
    connect(m_backgroundColorButton, SIGNAL(colorChanged(QColor)), this, SLOT(setBackgroundColor(QColor)) );
    connect(m_lineColorButton, SIGNAL(colorChanged(QColor)), this, SLOT(setLineColor(QColor)) );
    connect(m_spinBox, SIGNAL(valueChanged(double)), this, SLOT(setLineWidth(qreal)) );
}

void StyleWidget::setBackgroundColor(const QColor &color) {
    Graphic::Style* style = currentStyle();
    if(style != nullptr)
        style->setBrush(color);
}

void StyleWidget::setLineColor(const QColor &color) {
    Graphic::Style* style = currentStyle();
    if(style != nullptr) {
        QPen pen = style->pen() ;
        pen.setBrush(color);
        style->setPen(pen);
    }
}


void StyleWidget::setLineWidth(qreal width) {
    Graphic::Style* style = currentStyle();
    if(style != nullptr) {
        QPen pen = style->pen() ;
        pen.setWidth(width);
        style->setPen(pen);
    }
}

Graphic::Style* StyleWidget::currentStyle() const {
    QModelIndex currentIndex = m_listView->currentIndex();
    if(currentIndex.isValid())
        return m_model->styleAt(currentIndex.row());
    else
        return nullptr;
}
