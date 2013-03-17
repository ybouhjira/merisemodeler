#ifndef GRAPHICSTYLE_H
#define GRAPHICSTYLE_H

#include "namespace.h"

// Qt
#include <QObject>
#include <QFont>
#include <QBrush>
#include <QPen>

/**
 * @brief La classe GraphicStyle stock les informations relatives au style
 * graphique dee element de type GraphicObject. Elle rasssemble le remplissage
 * de type QBrush, le style de trait de type QPen, et la police de type QFont
 */
class Graphic::Style: public QObject
{
    Q_OBJECT
    // METHODES
public:
    // static
    static Style* getDefaultStyle();

    // non static
    /**
     * @brief Constructeur
     * @param parent Objet parent
     */
    Style(
            QBrush const& brush = QBrush(Qt::white),
            QPen const& pen = QPen(),
            QFont const& font = QFont(),
            QObject *parent = nullptr);
    
    virtual ~Style();

    // Accesseurs
    /**
     * @brief Accesseur
     * @return La police
     */
    QFont font() const;

    /**
     * @brief Accesseur
     * @return Le remplissage
     */
    QBrush brush() const;

    /**
     * @brief Accesseur
     * @return Le style de trait
     */
    QPen pen() const;

signals:
    /**
     * @brief Emit lorsque la police change
     */
    void fontChanged(QFont);

    /**
     * @brief Emit lorsque le remplissage change
     */
    void brushChanged(QBrush);

    /**
     * @brief Emit lorsque le style de trait change
     */
    void penChanged(QPen);

public slots:
    /**
     * @brief Mutateur
     * @param font Police
     */
    void setFont(QFont const& font) ;

    /**
     * @brief Mutateur
     * @param pen Trait
     */
    void setPen(QPen const& pen) ;

    /**
     * @brief Mutateur
     * @param brush remplissage
     */
    void setBrush(QBrush const& brush) ;

    // ATTRIBUTS
private:
    // static
    static Style *m_defaultStyle;

    // non static
    /**
     * @brief remplissage
     */
    QBrush m_brush;

    /**
     * @brief Police
     */
    QFont m_font;

    /**
     * @brief Trait
     */
    QPen m_pen;
};

#endif // GRAPHICSTYLE_H
