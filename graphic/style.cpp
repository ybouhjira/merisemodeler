#include "style.h"

using namespace Graphic;

Style* Style::m_defaultStyle = nullptr ;

Style* Style::getDefaultStyle() {
    if(m_defaultStyle == nullptr)
        m_defaultStyle = new Style(
                    QBrush(Qt::white),
                    QPen(QBrush(Qt::black), 1 ),
                    QFont("Arial")
                    );
    return m_defaultStyle;
}

Style::Style(
        QBrush const &brush,
        QPen const &pen,
        QFont const &font,
        QObject *parent)
    : QObject(parent)
    , m_brush(brush)
    , m_font(font)
    , m_pen(pen)
{
}

Style::~Style() {

}

void Style::setFont(const QFont &font) {
    m_font = font;
    emit fontChanged(font);
}

void Style::setBrush(const QBrush &brush) {
    m_brush = brush;
    emit brushChanged(brush);
}

void Style::setPen(const QPen &pen) {
    m_pen = pen;
    emit penChanged(pen);
}

QFont Style::font() const {
    return m_font;
}

QBrush Style::brush() const {
    return m_brush;
}

QPen Style::pen() const {
    return m_pen;
}

