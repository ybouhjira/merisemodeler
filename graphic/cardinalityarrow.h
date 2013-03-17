#ifndef CardinalityArrow_H
#define CardinalityArrow_H

#include "arrow.h"
#include "logic/associationlink.h"

// Qt
class QGraphicsSimpleTextItem;

/**
 * @brief CardinalityArrow est une fléche qui affiche les cardinalités
 */
class Graphic::CardinalityArrow : public Graphic::Arrow
{
    Q_OBJECT

    // METHODES
public:
    /**
     * @brief Construit une fléche sur laquel apparisse les cardinaliés min
     * et max, les autres paramétres sont passé au constructeur de la classe
     * @ref Arrow
     */
    CardinalityArrow(
            Logic::Link::Cardinality min,
            Logic::Link::Cardinality max,
            Object *source,
            Object *destination,
            qreal positionOnSource = 0.5,
            qreal positionOnDestination = 0.5,
            QGraphicsItem *parent = 0
            );

    /**
     * @brief Destructeur
     */
    virtual ~CardinalityArrow() ;

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
     * @brief Appele Arrow::redraw() et met à jour la position du text
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
    CardinalityTextItem *m_text;

    
};

#endif // CardinalityArrow_H
