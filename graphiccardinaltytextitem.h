#ifndef GRAPHICCARDINALTYTEXTITEM_H
#define GRAPHICCARDINALTYTEXTITEM_H

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
            AssociationLink::Cardinality min = AssociationLink::Zero,
            AssociationLink::Cardinality max = AssociationLink::N
            );

    // Redefinitions
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    
    // Accesseurs
    /**
     * @brief Accesseur
     * @return  Cardinalité minimum
     */
    AssociationLink::Cardinality min() const;

    /**
     * @brief Accesseur
     * @return Cardinalité maximum
     */
    AssociationLink::Cardinality max() const;

    // Mutateurs
    /**
     * @brief mutateur
     * @param Cardinalité minimum
     */
    void setMin(AssociationLink::Cardinality min);

    /**
     * @brief Mutateur
     * @param Cardinalité maximum
     */
    void setMax(AssociationLink::Cardinality max);

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
    AssociationLink::Cardinality m_min ;

    /**
     * Cardinalité maximum
     **/
    AssociationLink::Cardinality m_max;

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
