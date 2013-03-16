#ifndef GRAPHICCARDINALITYARROW_H
#define GRAPHICCARDINALITYARROW_H

#include "graphicarrow.h"
#include "associationlink.h"
class GraphicCardinalityTextItem;

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
            Logic::Link::Cardinality min,
            Logic::Link::Cardinality max,
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
    Logic::Link::Cardinality min() const;

    /**
     * @brief Accesseur
     * @return Cardinalité maximum
     */
    Logic::Link::Cardinality max() const;

    // Mutateurs
public slots:
    /**
     * @brief Mutateur
     * @param min Cardinalité minimum
     */
    void setMin(Logic::Link::Cardinality min);

    /**
     * @brief Mutateur
     * @param max Cardinalité maximum
     */
    void setMax(Logic::Link::Cardinality max);

    /**
     * @brief Appele GraphicArrow::redraw() et met à jour la position du text
     * de la cardinalité
     * @reimp
     */
    void redraw();

    // ATTRIBUTS
private:
    /**
     * @brief Cardinalé minimum
     */
    Logic::Link::Cardinality m_min;

    /**
     * @brief Cardinalité maximum
     */
    Logic::Link::Cardinality m_max;

    /**
     * @brief Le texte represnetant les cardinalité
     */
    GraphicCardinalityTextItem *m_text;

    
};

#endif // GRAPHICCARDINALITYARROW_H
