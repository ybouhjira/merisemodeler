#include "xmlitem.h"

XMLItem::XMLItem(Item *item, QXmlStreamWriter *writer,QXmlStreamReader *reader)
    : m_item(item)
    , m_writer(writer)
    , m_reader(reader)
{
}

XMLItem::~XMLItem()
{

}

void XMLItem::WriteItem()
{
    m_writer->writeStartElement("item");
    m_writer->writeAttribute("name",m_item->name());
    writeProperties(m_item->properties(),"properties");
    m_writer->writeEndElement();
}
Item* XMLItem::ReadItem()
{
    QList<Property*> properties;
    while(!m_reader->atEnd())
    {
    if(m_reader->isStartElement() && m_reader->name() =="item")
    {
        QString name;
        name =  m_reader->attributes().value("name").toString();

    }else if(m_reader->isStartElement() && m_reader->name() == "properties")
    {
        m_reader->readNext();
    }else if(m_reader->isStartElement() && m_reader->name() =="property")
    {
        QString name = m_reader->attributes().value("name").toString();
        QString typeName = m_reader->attributes().value("type").toString();
        QString Obligatory = m_reader->attributes().value("obligatory").toString();
        QString defaultVal = m_reader->attributes().value("defaultValue").toString();
        QString check = m_reader->attributes().value("check").toString();
        QString identifier = m_reader->attributes().value("identifier").toString();
        Type T(typeName);
        bool Ob;
        if(Obligatory == "true")
            Ob = true;
        else
            Ob = false;
        bool Id;
        if(identifier == "true")
            Id = true;
        else
            Id = false;

        Property *p = new Property(name,T,Ob,check,defaultVal,Id);
        properties.append(p);
    }
    else
    {
        m_reader->readNext();
    }
    }
}
void XMLItem::writeProperties(QList<Property *> properties, QString const &name)
{
    m_writer->writeStartElement(name);
    foreach (Property *Pte,properties) {
        m_writer->writeStartElement("property");
        m_writer->writeAttribute("name",Pte->name());
        m_writer->writeAttribute("type",Pte->type().name());
        QString Ob;
        if(Pte->isObligatory() == true)
            Ob = "true";
        else
            Ob = "false";
        m_writer->writeAttribute("obligatory",Ob);
        m_writer->writeAttribute("defaultValue",Pte->defaultValue());
        m_writer->writeAttribute("check",Pte->check());
        QString Id;
        if(Pte->isIdentifier() == true)
            Id = "true";
        else
            Id = "false";
        m_writer->writeAttribute("identifier",Id);
        m_writer->writeEndElement();
    }
    m_writer->writeEndElement();
}
QList<Property*> XMLItem::readProperties()
{

}
