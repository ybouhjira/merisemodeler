#ifndef ASSOCIATION_H
#define ASSOCIATION_H


#include "item.h"
#include "graphicassociation.h"
#include "associationlink.h"
class Entity;

// Qt
#include <QPair>
class QString;

// TYPEDEFS
typedef QPair<AssociationLink*, AssociationLink*> AssociationLinkPair;

/**
 * @brief La classe Association decris le lien sémantique entre 2 entités
 */
class Association : public Item
{
public:
    /**
     * @brief Constructeur
     * @param name nom de l'association
     * @param links un objet de type QPair contenant deux liens entre cette
     * association et deux entités.
     */
    Association(
            QString const &name
            ,QPair<AssociationLink*, AssociationLink*> links);

    /**
     * @overload Association()
     * @brief Construit liée à deux entité avec des cardinalité
     * @param name Nom de l'association
     * @param first Entité 1
     * @param second Entité 2
     * @param firstMin cardinalité minimum pour l'entité first
     * @param firstMax cardinalité maximum pour l'entité first
     * @param secondMin cardinalité minimum pour l'entité second
     * @param secondMax cardinalité maximum pour l'entité second
     */
    Association(
            QString const &name,
            Entity *first,
            Entity *second,
            AssociationLink::Cardinality firstMin = AssociationLink::Zero,
            AssociationLink::Cardinality firstMax = AssociationLink::N,
            AssociationLink::Cardinality secondMin = AssociationLink::Zero,
            AssociationLink::Cardinality secondMax = AssociationLink::N);

    /**
     * @brief Destructeur
     */
    virtual ~Association();

    // Redefinition
    /**
     * @reimp Item::graphicObject()
     */
    GraphicAssociation* graphicObject() const;

    // Accesseurs et mutateurs
    /**
     * @brief Mutateur
     * @param gassoc Representation graphique de cette association
     */
    void setGraphicObject(GraphicAssociation* gassoc);

    /**
     * @brief Accesseur
     * @return Liens
     */
    QPair<AssociationLink*, AssociationLink*> links() const ;

    /**
     * @brief Change le prmier lien
     */
    void setFirstLink(AssociationLink* firstLink);

    /**
     * @brief Change le deuxième lien
     */
    void setSecondLink(AssociationLink* secondLink);

    /**
     * @brief Retourne la première entité
     * @remarks Cette méthodes est équivalant à
     * @code
     *     association.links().first.entity() ;
     * @endcode
     */
    Entity* firstEntity() const;

    /**
     * @brief Retourne la deuxième entité
     * @see Association::firstEntity()
     */
    Entity* secondEntity() const;

private:
    /**
     * @brief Liens
     */
    QPair<AssociationLink*, AssociationLink*> m_links;

    /**
     * @brief Respresentation graphique
     */
    GraphicAssociation* m_graphicAssociation;
};

#endif // ASSOCIATION_H
