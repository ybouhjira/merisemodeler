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
    emit nameChanged();
}

void Item::addProperty(Property *property)
{
    m_properties.append(property);
    emit propertiesEdited();
}
void Item::setProperties(QList<Property *> properties)
{
    m_properties.swap(properties);
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



pugi::xml_node Item::writeProperties()
{
    pugi::xml_node Xproperties;
    foreach (Property *Pte, properties()) {
        pugi::xml_node Xpte = Xproperties.append_child("property");

        //Récupération des données
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

        //Ajout des attributs
        Xpte.append_attribute("name") = Pte->name().toStdString().c_str();
        Xpte.append_attribute("type") = Pte->type().name().toStdString().c_str();
        Xpte.append_attribute("identifier") = Id.toStdString().c_str();
        Xpte.append_attribute("obligatory") = Ob.toStdString().c_str();
        Xpte.append_attribute("check") = Pte->check().toStdString().c_str();
        Xpte.append_attribute("default-value") = Pte->defaultValue().toStdString().c_str();
    }

    return Xproperties;
}

pugi::xml_node Item::writeUK(QList<UniqueConstraint *> uniqueConstraints)
{
    pugi::xml_node Xuk;
    foreach (UniqueConstraint *uk, uniqueConstraints) {
        pugi::xml_node unique = Xuk.append_child("Unique-Constraint");

        //Les propietés de chaque contrainte
        foreach (Property *p, uk->properties()) {
            pugi::xml_node ukProperty = unique.append_child("Unique-Constraint-Property");
            ukProperty.append_attribute("name") = p->name().toStdString().c_str();
        }
    }
    return Xuk;
}
