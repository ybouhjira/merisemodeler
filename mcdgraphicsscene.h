#ifndef MCDGRAPHICSSCENE_H
#define MCDGRAPHICSSCENE_H

class McdModel;
// Qt
#include <QGraphicsScene>

/**
 * @brief Cette class est une sous class de QGraphicsScene qui contient
 * les elements graphique representant le MCD comme @ref GraphicEntity, et
 * @ref GraphicAsssociation
 */
class McdGraphicsScene : public QGraphicsScene
{
    Q_OBJECT
    // TYPES
public:
    /**
     * @brief Définit le model actuel de McdGraphicsScene
     */
    enum Mode {
        AddEntity,       //! Mode d'ajout d'une entité
        AddAssociation,  //! Mode d'ajout d'une association
        Remove,          //! Mode de supression
        None             //! Rien
    };

    // METHODES
public:
    /**
     * @brief Constructeur
     * @param mcd Model MCD à representer
     * @param parent QObject parent qui se charge de la destruction de
     * cet objet
     */
    McdGraphicsScene(McdModel *mcd = nullptr);

    /**
     * @brief Destructeur
     */
    virtual ~McdGraphicsScene();

    /**
     * @brief Accesseur
     * @return Mode actuel
     */
    Mode mode() const;

public slots:
    /**
     * @brief Mutateur
     * @param mode Mode
     */
    void setMode(Mode const& mode);

    // ATTRIBUTS
private:
    /**
     * @brief Le MCD
     */
    McdModel *m_mcd;

    /**
     * @brief Mode
     */
    Mode m_mode;
};

#endif // MCDGRAPHICSSCENE_H
