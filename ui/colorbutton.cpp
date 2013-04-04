#include "colorbutton.h"

#include <QColorDialog>

using namespace Ui;

ColorButton::ColorButton(QColor const& color, QWidget *parent) :
    QPushButton(parent)
  , m_color(color)
{
    updateButton();

    connect(this, &QPushButton::clicked, [this]() {
        QColor selectedColor = QColorDialog::getColor(m_color, parentWidget());
        if(selectedColor.isValid()) {
            m_color  = selectedColor;
            updateButton();
            emit colorChanged(m_color);
            emit colorEdited(m_color);
        }
    });
}

void ColorButton::setColor(QColor const& color) {
    m_color = color;
    updateButton();
    emit colorEdited(m_color);
}

QColor ColorButton::color() const {
    return m_color;
}

void ColorButton::updateButton() {
    QPixmap pixmap(60, 60);
    pixmap.fill(m_color);
    setIcon(pixmap);
    setText(m_color.name());
}
