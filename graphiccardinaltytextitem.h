#ifndef GRAPHICCARDINALTYTEXTITEM_H
#define GRAPHICCARDINALTYTEXTITEM_H

#include "logic/namespace.h"
#include "associationlink.h"
class GraphicCardinalityArrow;
// Qt
#include <QGraphicsSimpleTextItem>

/**
 * @brief Un QGraphicsSimpleTextItem qui affiche des cardinalités et suit
 * la fléche
 */
class GraphicCardinalityTextItem : public QGraphicsSimpleTextItem
{
    // METHODES
public:
    GraphicCardinalityTextItem(
            GraphicCardinalityArrow* parentArrow,
            Logic::Link::Cardinality min = Logic::Link::Zero,
            Logic::Link::Cardinality max = Logic::Link::N
            );

    // Redefinitions
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    
    // Accesseurs
    /**
     * @brief Accesseur
     * @return  Cardinalité minimum
     */
    Logic::Link::Cardinality min() const;

    /**
     * @brief Accesseur
     * @return Cardinalité maximum
     */
    Logic::Link::Cardinality max() const;

    // Mutateurs
    /**
     * @brief mutateur
     * @param Cardinalité minimum
     */
    void setMin(Logic::Link::Cardinality min);

    /**
     * @brief Mutateur
     * @param Cardinalité maximum
     */
    void setMax(Logic::Link::Cardinality max);

    /**
     * @brief Met à jour la les coordonés dans le repaire dont le centre est le
     * point de destination
     */
    void updatePosOnDestCoordinates();

private:
    /**
     * @brief Met à jour le texte
     */
    void updateText();

    // ATTRIBUTS
private:



    /**
     * Cardinalité minimum
     **/
    Logic::Link::Cardinality m_min ;

    /**
     * Cardinalité maximum
     **/
    Logic::Link::Cardinality m_max;

    /**
     * @brief Position du text dans le repére dont le centre est le point de
     * destination de la fléche
     */
    QPointF m_posOnDestPointCoordinates;

    /**
     * @brief Fléche sur laquelle est accroché cette cardinalité
     **/
    GraphicCardinalityArrow *m_parentArrow;
};

#endif // GRAPHICCARDINALTYTEXTITEM_H
