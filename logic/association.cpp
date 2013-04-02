#include "association.h"
#include "associationlink.h"
#include "logic/entity.h"
#include "pugixml/pugixml.hpp"

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
pugi::xml_node Association::toXml()
{
    pugi::xml_node root;
    root.set_name("association");
    root.append_attribute("name") = name().toStdString().c_str();

    //Ecriture des propriétés de l'association
    writeProperties() = root.append_child("properties");

    //Ecriture de la premiére entité
    pugi::xml_node E1 = root.append_child("entity1");
    E1.append_attribute("name") = entity1()->name().toStdString().c_str();
    //

    //Ecriture de la deuxiéme entité
    pugi::xml_node E2 = root.append_child("entity2");
    E2.append_attribute("name") = entity2()->name().toStdString().c_str();

    //Graphic properties
    pugi::xml_node GProperties = root.append_child("graphic");
    pugi::xml_node X = GProperties.append_child("x");
    X.append_attribute("x") = QString::number(graphicObject()->x()).toStdString().c_str();
    pugi::xml_node Y = GProperties.append_child("y");
    Y.append_attribute("y") = QString::number(graphicObject()->y()).toStdString().c_str();
    pugi::xml_node W = GProperties.append_child("width");
    W.append_attribute("width") = QString::number(graphicObject()->width()).toStdString().c_str();
    pugi::xml_node H = GProperties.append_child("height");
    H.append_attribute("height") = QString::number(graphicObject()->height()).toStdString().c_str();

    return root;
}
Logic::Association* Association::fromXml(pugi::xml_node assoc)
{
    //association's name
    QString AName = assoc.attribute("name").value();

    //Reading association's properties
    pugi::xml_node assocProperties = assoc.child("properties");
    QList<Logic::Property*> propertiesList;
    foreach (pugi::xml_node Xproperty, assocProperties.children("property")) {
        //Property attributes
        QString name = Xproperty.attribute("name").value();
        QString type = Xproperty.attribute("type").value();
        QString check = Xproperty.attribute("check").value();
        QString defaultValue = Xproperty.attribute("default-value").value();
        QString identifier = Xproperty.attribute("identifier").value();
        QString obligatory = Xproperty.attribute("obligtory").value();
        bool id = (identifier == "true")?true:false;
        bool ob = (obligatory == "true")?true:false;
        Type T(type);
        //Appending property to the Property list
        propertiesList.append(new Property(name,T,ob,check,defaultValue,id));
    }

    Association *association = new Association(AName,);
    association->setProperties(propertiesList);

    return association;
}



