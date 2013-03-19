#include "xmlentity.h"

XMLEntity::XMLEntity(Entity *entity,QXmlStreamWriter *writer,QXmlStreamReader *reader)
    : m_entity(entity)
    , m_writer(writer)
    , m_reader(reader)
{
}
XMLEntity::~XMLEntity()
{
}

void XMLEntity::writeEntity()
{
    m_writer->writeStartElement("entity");
    m_writer->writeAttribute("name",m_entity->name());

    //Writing properties
    writeProperties(m_entity->properties(),"properties");

    //Writing uniqueConstraints
    m_writer->writeStartElement("UniqueConstraints");
    foreach (UniqueConstraint *U, m_entity->uniqueConstraints()) {
        m_writer->writeStartElement("UniqueConstraint");
        writeProperties(U->properties(),"UCProperties");
        m_writer->writeEndElement();
    }
    m_writer->writeEndElement();

    //Writing Parents
    if(m_entity->hasParents())
    {
        m_writer->writeStartElement("Parents");
        foreach (Entity *parent, m_entity->parents())
        {
            m_writer->writeStartElement("parent");
            m_writer->writeAttribute("name",parent->name());
            m_writer->writeEndElement();
        }
    }

    //Writing entity position
    m_writer->writeStartElement("position");
    m_writer->writeAttribute("X",QString::number(m_entity->graphicObject()->x()));
    m_writer->writeAttribute("Y",QString::number(m_entity->graphicObject()->y()));

    //writing metrics
    m_writer->writeStartElement("metrics");
    m_writer->writeAttribute("width",QString::number(m_entity->graphicObject()->width()));
    m_writer->writeAttribute("height",QString::number(m_entity->graphicObject()->height()));
    m_writer->writeAttribute("radius",QString::number(m_entity->graphicObject()->radius()));

    m_writer->writeEndElement();
}

Entity* XMLEntity::readEntity()
{
    /**QString entityName ;
    while(!m_reader->atEnd())
    {
        if(m_reader->isStartElement() && m_reader->name() == "entity")
        {
            entityName = m_reader->attributes().value("name").toString();
        }else if(m_reader->isStartElement() && (m_reader->name()=="properties" || m_reader->name() == "UCProperties"))
        {
            if(m_reader->name()=="properties")
            {
                m_reader->readNext();
                //I don't know what to dooo :(

            }

        else if()
        {

        }
    }**/
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
