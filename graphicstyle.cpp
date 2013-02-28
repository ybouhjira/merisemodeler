#include "graphicstyle.h"

GraphicStyle* GraphicStyle::m_defaultStyle = nullptr;

GraphicStyle* GraphicStyle::getDefaultStyle() {
    if(m_defaultStyle == nullptr)
        m_defaultStyle = new GraphicStyle();
    return m_defaultStyle;
}

GraphicStyle::GraphicStyle(
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

GraphicStyle::~GraphicStyle() {

}

void GraphicStyle::setFont(const QFont &font) {
    m_font = font;
    emit fontChanged(font);
}

void GraphicStyle::setBrush(const QBrush &brush) {
    m_brush = brush;
    emit brushChanged(brush);
}

void GraphicStyle::setPen(const QPen &pen) {
    m_pen = pen;
    emit penChanged(pen);
}

QFont GraphicStyle::font() const {
    return m_font;
}

QBrush GraphicStyle::brush() const {
    return m_brush;
}

QPen GraphicStyle::pen() const {
    return m_pen;
}

