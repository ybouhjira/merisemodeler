#include "xmlassociation.h"
#include "entity.h"
#include "graphicarrow.h"
#include "graphicstyle.h"
#include <QPair>

XMLAssociation::XMLAssociation(Association *assoc, QXmlStreamWriter *writer,QXmlStreamReader *reader)
    :m_assoc(assoc)
    ,m_writer(writer)
    ,m_reader(reader)
{
}

XMLAssociation::~XMLAssociation()
{

}

void XMLAssociation::writeAssociation()
{
    m_writer->writeStartElement("association");
    m_writer->writeAttribute("name",m_assoc->name());
    QPair<AssociationLink*, AssociationLink*> P = m_assoc->links();
    //Premiere entité
    m_writer->writeStartElement("firstEntity");
    m_writer->writeAttribute("name",m_assoc->entity1()->name());
    m_writer->writeAttribute("cardinalityMax",P.first->max());
    m_writer->writeAttribute("cardinalityMin",P.first->min());
    //Deuxiéme entité
    m_writer->writeStartElement("secondEntity");
    m_writer->writeAttribute("name",m_assoc->entity2()->name());
    m_writer->writeAttribute("cardinalityMax",P.second->max());
    m_writer->writeAttribute("cardinalityMin",P.second->min());

    m_writer->writeStartElement("graphicAssociation");
    m_writer->writeAttribute("x",QString::number(m_assoc->graphicObject()->x()));
    m_writer->writeAttribute("y",QString::number(m_assoc->graphicObject()->y()));
    m_writer->writeAttribute("width",QString::number(m_assoc->graphicObject()->width()));
    m_writer->writeAttribute("height",QString::number(m_assoc->graphicObject()->height()));
    m_writer->writeAttribute("radius",QString::number(m_assoc->graphicObject()->radius()));

    //Les Fléches grahiques
    QPair<GraphicArrow*,GraphicArrow*> arrows = m_assoc->graphicObject()->arrows();
    m_writer->writeStartElement("arrows");
    //Premier Fléche
    m_writer->writeStartElement("arrow1");
    m_writer->writeAttribute("x",QString::number(arrows.first->x()));
    m_writer->writeAttribute("y",QString::number(arrows.first->y()));
    //Premier Fléche
    m_writer->writeStartElement("arrow1");
    m_writer->writeAttribute("x",QString::number(arrows.second->x()));
    m_writer->writeAttribute("y",QString::number(arrows.second->y()));

    m_writer->writeStartElement("graphic");
    m_writer->writeAttribute("color",QString::number(m_assoc->graphicObject()->style()->brush().color().value()));
    m_writer->writeAttribute("",m_assoc->graphicObject()->style()->pen().);











}
