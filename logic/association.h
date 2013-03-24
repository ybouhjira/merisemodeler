#ifndef ASSOCIATION_H
#define ASSOCIATION_H

#include "item.h"
#include "graphic/association.h"
#include "associationlink.h"
#include "logic/namespace.h"
#include "xml/serializable.h"

// Qt
#include <QPair>
class QString;

// TYPEDEFS
typedef QPair<Logic::Link*, Logic::Link*> LinksPair;

/**
 * @brief La classe Association decris le lien sémantique entre 2 entités
 */
class Logic::Association : public Logic::Item , public Serializable
{
public:
    /**
     * @brief Constructeur
     * @param name nom de l'association
     * @param links un objet de type QPair contenant deux liens entre cette
     * association et deux entités.
     */
    Association(QString const &name, LinksPair links);

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
            Logic::Link::Cardinality firstMin = Logic::Link::Zero,
            Logic::Link::Cardinality firstMax = Logic::Link::N,
            Logic::Link::Cardinality secondMin = Logic::Link::Zero,
            Logic::Link::Cardinality secondMax = Logic::Link::N);

    /**
     * @brief Destructeur
     */
    virtual ~Association();

    // Redefinition
    /**
     * @reimp Item::graphicObject()
     */
    Graphic::Association* graphicObject() const;

    // Accesseurs et mutateurs
    /**
     * @brief Mutateur
     * @param gassoc Representation graphique de cette association
     */
    void setGraphicObject(Graphic::Association* gassoc);

    /**
     * @brief Accesseur
     * @return Liens
     */
    LinksPair links() const ;

    /**
     * @brief Change le prmier lien
     */
    void setFirstLink(Logic::Link* firstLink);

    /**
     * @brief Change le deuxième lien
     */
    void setSecondLink(Logic::Link* secondLink);

    /**
     * @brief Retourne la première entité
     * @remarks Cette méthodes est équivalant à
     * @code
     *     association.links().first.entity() ;
     * @endcode
     */
    Logic::Entity* entity1() const;

    /**
     * @brief Retourne la deuxième entité
     * @see Association::firstEntity()
     */
    Logic::Entity* entity2() const;

    /**
     * @brief Serialiser un Item en un xml_node classe de la librrie
     * @return
     */
    xml_node toXml();

    /**
     * @brief Obtenir l'objet du XML
     * @param node
     */
    void fromXml(xml_node node);


private:
    /**
     * @brief Liens
     */
    QPair<Logic::Link*, Logic::Link*> m_links;

    /**
     * @brief Respresentation graphique
     */
    Graphic::Association* m_graphicAssociation;
};

#endif // ASSOCIATION_H
