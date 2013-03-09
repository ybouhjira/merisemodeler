#ifndef GRAPHICOBJECT_H
#define GRAPHICOBJECT_H

#include <QGraphicsObject>
class GraphicStyle;

/**
 * @brief La classe GraphicObject est la classe abstraite qui regroupe tous
 * les objets graphiques représenté par l'application.
 * Elle hérite de QGraphicsObject, pour bénificier du mécanisme des signals et
 * slots.
 */
class GraphicObject : public QGraphicsObject
{
    Q_OBJECT

    // METHODESS
protected:
    /**
      * @brief Constructeur
      * @param parent Element parent
      */
    GraphicObject(QGraphicsItem* parent) ;

public:
    /**
     * @brief Destructeur
     */
    virtual ~GraphicObject() ;

    // Accesseurs
    /**
     * @brief Accesseur
     * @return Style graphique
     */
    GraphicStyle* style() const;

    // Redefinitions
    /**
     * @reimp initialise les parametres de l'instance de QPainter utilisé avec
     * les valeurs du style graphique
     */
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option, QWidget *) override;
signals:
    /**
     * @brief Emit lorsque le style graphique change
     */
    void styleChanged(GraphicStyle*);

public slots:
    /**
     * @brief Mutateur
     * @param style Style graphique
     */
    void setStyle(GraphicStyle* style);

    // ATTRIBUTS
private:
    /**
     * @brief Style graphique
     */
    GraphicStyle *m_style;

};

#endif // GRAPHICOBJECT_H
