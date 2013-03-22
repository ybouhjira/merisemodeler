#include "item.h"
#include "property.h"

using namespace Logic;

Item::Item(QString const & name)
    : m_name(name)
{
}

Item::~Item()
{
    for(int i=0;i<m_properties.length();i++)
        delete m_properties.at(i);
}

QString Item::name() const
{
    return m_name;
}

void Item::setName(QString const &name)
{
    m_name = name;
}

void Item::addProperty(Property *property)
{
    m_properties.append(property);
    emit propertiesEdited();
}

void Item::removeProperty(int index)
{
    m_properties.removeAt(index);
}

void Item::removeProperty(Property *property)
{
    m_properties.removeOne(property);
}

QList<Logic::Property*> Item::properties() {
    return m_properties;
}

xml_node Item::toXml()
{
    return new xml_node();
}

void Item::fromXml(xml_node node)
{
}

xml_node Item::writeProperties()
{
    xml_node Xproperties;
    Xproperties.set_name("properties");
    foreach (Property *Pte, properties()) {
        xml_node Xpte;
        Xpte.set_name("property");
        //test Si la proprieté est obligatoire
        QString Ob;
        if(Pte->isObligatory() == true)
            Ob = "true";
        else
            Ob = "false";
        //test si la propieté est un idantifiant
        QString Id;
        if(Pte->isIdentifier() == true)
            Id = "true";
        else
            Id = "false";
        Xpte.append_attribute("name") = Pte->name().toStdString();
        Xpte.append_attribute("identifier") = Id;
        Xpte.append_attribute("obligatory") = Ob;
        Xpte.append_attribute("check") = Pte->check().toStdString();
        Xpte.append_attribute("default-value") = Pte->defaultValue().toStdString();
        Xproperties.append_child(Xpte);
    }
    return Xproperties;
}

xml_node Item::writeUK(QList<UniqueConstraint *> uniqueConstraints)
{
    xml_node Xuk;
    Xuk.set_name("Unique-Constraints");
    foreach (UniqueConstraint *uk, uniqueConstraints) {
        xml_node unique;
        unique.set_name("Unique-Constraint");
        //Les propietés de chaque contrainte
        foreach (Property *p, uk->properties()) {
            xml_node ukProperty;
            ukProperty.set_name("Unique-Constraint-Property");
            ukProperty.append_attribute("name") = p->name().toStdString();
            unique.append_child(ukProperty);
        }
        Xuk.append_child(unique);
    }
    return Xuk;
}
