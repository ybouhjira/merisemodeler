#ifndef COLORBUTTON_H
#define COLORBUTTON_H

#include "namespace.h"

#include <QPushButton>
#include <QColor>

class Ui::ColorButton : public QPushButton
{
    Q_OBJECT
public:
    explicit ColorButton(QColor const& color = QColor(), QWidget *parent = 0);
    
    QColor color() const ;
signals:
    void colorChanged(QColor const& color);

public slots:
    void setColor(QColor const& color);

private:
    void updateButton();

private:
    QColor m_color;
};

#endif // COLORBUTTON_H
