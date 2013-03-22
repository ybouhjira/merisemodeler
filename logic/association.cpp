#include "association.h"
#include "associationlink.h"

using namespace Logic;

Association::Association(QString const &name
                         ,LinksPair links)
    : Item(name)
    , m_links(links)
{
}

Association::Association(
        QString const &name,
        Entity *first,
        Entity *second,
        Link::Cardinality firstMin,
        Link::Cardinality firstMax,
        Link::Cardinality secondMin,
        Link::Cardinality secondMax
        )
    : Association( //< Appel de l'autre constructeur
          name,
          QPair<Link*, Link*>(
              new Link(first, firstMin, firstMax),
              new Link(second, secondMin, secondMax )
              )
          )
{

}

Association::~Association()
{
}

QPair<Link*, Link*> Association::links() const {
    return m_links ;
}

void Association::setFirstLink(Link *firstLink) {
    m_links.first = firstLink ;
}

void Association::setSecondLink(Link* secondLink) {
    m_links.second = secondLink;
}

Graphic::Association *Association::graphicObject() const {
    return m_graphicAssociation ;
}

void Association::setGraphicObject(Graphic::Association *gassoc) {
    m_graphicAssociation = gassoc;
}

Entity* Association::entity1() const {
    if(m_links.first != nullptr)
        return m_links.first->entity();
    else
        return nullptr;
}

Entity* Association::entity2() const {
    if(m_links.second != nullptr)
        return m_links.second->entity();
    else
        return nullptr;
}
xml_node Association::toXml()
{
    xml_node node;
    return node;
}
void Association::fromXml(xml_node node)
{

}
