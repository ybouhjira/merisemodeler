#ifndef GRAPHICCARDINALITYARROW_H
#define GRAPHICCARDINALITYARROW_H

#include "graphicarrow.h"
#include "associationlink.h"

// Qt
class QGraphicsSimpleTextItem;

/**
 * @brief GraphicCardinalityArrow est une fléche qui affiche les cardinalités
 */
class GraphicCardinalityArrow : public GraphicArrow
{
    Q_OBJECT

    // METHODES
public:
    /**
     * @brief Construit une fléche sur laquel apparisse les cardinaliés min
     * et max, les autres paramétres sont passé au constructeur de la classe
     * @ref GraphicArrow
     */
    GraphicCardinalityArrow(
            AssociationLink::Cardinality min,
            AssociationLink::Cardinality max,
            GraphicObject *source,
            GraphicObject *destination,
            qreal positionOnSource = 0.5,
            qreal positionOnDestination = 0.5,
            QGraphicsItem *parent = 0
            );

    /**
     * @brief Destructeur
     */
    virtual ~GraphicCardinalityArrow() ;

    // Accesseurs
    /**
     * @brief Accesseur
     * @return Cardinalité minimum
     */
    AssociationLink::Cardinality min() const;

    /**
     * @brief Accesseur
     * @return Cardinalité maximum
     */
    AssociationLink::Cardinality max() const;

    // Mutateurs
public slots:
    /**
     * @brief Mutateur
     * @param min Cardinalité minimum
     */
    void setMin(AssociationLink::Cardinality min);

    /**
     * @brief Mutateur
     * @param max Cardinalité maximum
     */
    void setMax(AssociationLink::Cardinality max);

    // ATTRIBUTS
private:
    /**
     * @brief Cardinalé minimum
     */
    AssociationLink::Cardinality m_min;

    /**
     * @brief Cardinalité maximum
     */
    AssociationLink::Cardinality m_max;

    /**
     * @brief Le texte represnetant les cardinalité
     */
    QGraphicsSimpleTextItem *m_text;
    
};

#endif // GRAPHICCARDINALITYARROW_H
