#include "association.h"
#include "associationlink.h"

Association::Association(QString const &name
                         ,QPair<AssociationLink*, AssociationLink*> links)
    : Item(name)
    , m_links(links)
{
}

Association::Association(
        QString const &name,
        Entity *first,
        Entity *second,
        AssociationLink::Cardinality firstMin,
        AssociationLink::Cardinality firstMax,
        AssociationLink::Cardinality secondMin,
        AssociationLink::Cardinality secondMax
        )
    : Association( //< Appel de l'autre constructeur
          name,
          QPair<AssociationLink*, AssociationLink*>(
              new AssociationLink(first, firstMin, firstMax),
              new AssociationLink(second, secondMin, secondMax )
              )
          )
{

}

Association::~Association()
{
}

QPair<AssociationLink*, AssociationLink*> Association::links() const {
    return m_links ;
}

void Association::setFirstLink(AssociationLink *firstLink) {
    m_links.first = firstLink ;
}

void Association::setSecondLink(AssociationLink* secondLink) {
    m_links.second = secondLink;
}

GraphicAssociation* Association::graphicObject() const {
    return m_graphicAssociation ;
}

void Association::setGraphicObject(GraphicAssociation *gassoc) {
    m_graphicAssociation = gassoc;
}

Entity* Association::entity1() const {
    return m_links.first->entity();
}

Entity* Association::entity2() const {
    return m_links.second->entity();
}
