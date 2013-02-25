#ifndef GRAPHICOBJECT_H
#define GRAPHICOBJECT_H

#include <QGraphicsObject>

/**
 * @brief La classe GraphicObject est la classe abstraite qui regraoupe tous
 * les objets graphique représenté par l'application.
 * Elle hérite de QGraphicsObject, pour bénificier du mécanisme des signals et
 * slots.
 */
class GraphicObject : public QGraphicsObject
{
    Q_OBJECT
protected:
    /**
      * @brief Constructeur
      * @param parent Element parent
      */
    GraphicObject(QGraphicsItem* parent) ;
    /** @brief Destructeur */
    virtual ~GraphicObject() ;
};

#endif // GRAPHICOBJECT_H