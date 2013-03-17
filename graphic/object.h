#ifndef GRAPHICOBJECT_H
#define GRAPHICOBJECT_H


#include "namespace.h"

// Qt
#include <QGraphicsObject>


/**
 * @brief La classe Graphic::Object est la classe abstraite qui regroupe tous
 * les objets graphiques représenté par l'application.
 * Elle hérite de QGraphicsObject, pour bénificier du mécanisme des signals et
 * slots.
 */
class Graphic::Object : public QGraphicsObject
{
    Q_OBJECT

    // METHODESS
protected:
    /**
      * @brief Constructeur
      * @param parent Element parent
      */
    Object(QGraphicsItem* parent) ;

public:
    /**
     * @brief Destructeur
     */
    virtual ~Object() ;

    // Accesseurs
    /**
     * @brief Accesseur
     * @return Style graphique
     */
    Graphic::Style* style() const;

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
    void styleChanged(Graphic::Style*);

    /**
     * @brief Changement de la largeur
     */
    void widthChanged();

    /**
     * @brief Changement de la hauteur
     */
    void heightChanged();

public slots:
    /**
     * @brief Mutateur
     * @param style Style graphique
     */
    void setStyle(Graphic::Style* style);

    // ATTRIBUTS
private:
    /**
     * @brief Style graphique
     */
    Graphic::Style *m_style;

};

#endif // GRAPHICOBJECT_H
