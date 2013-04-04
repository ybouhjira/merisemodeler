#include "stylewidget.h"
#include "colorbutton.h"
#include "stylelistmodel.h"

#include <QListView>
#include <QVBoxLayout>
#include <QPushButton>
#include <QFormLayout>
#include <QFontComboBox>
#include <QDoubleSpinBox>

using namespace Ui;

StyleWidget::StyleWidget(QWidget *parent) : QWidget(parent)
  , m_model(new StyleListModel)
  , m_listView(new QListView)
  , m_applyButton(new QPushButton(tr("Apply")))
  , m_fontComboBox(new QFontComboBox)
  , m_backgroundColorButton(new ColorButton(Qt::white))
  , m_lineColorButton(new ColorButton(Qt::black))
  , m_spinBox(new QDoubleSpinBox)
{
    m_listView->setModel(m_model);

    auto layout = new QVBoxLayout(this);
    layout->addWidget(m_listView);
    layout->addWidget(m_applyButton);

    auto formLayout = new QFormLayout;
    layout->addLayout(formLayout);
    formLayout->addRow(tr("Font"), m_fontComboBox);
    formLayout->addRow(tr("Background color"), m_backgroundColorButton);
    formLayout->addRow(tr("Line color"), m_lineColorButton);
    formLayout->addRow(tr("Line width"), m_spinBox);
    m_spinBox->setMinimum(0.1);
    m_spinBox->setMaximum(10);
}
