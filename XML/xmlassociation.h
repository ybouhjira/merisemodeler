#ifndef XMLASSOCIATION_H
#define XMLASSOCIATION_H

#include "xmlitem.h"
#include "association.h"
#include <QXmlStreamReader>
#include <QXmlStreamWriter>

class XMLAssociation
{
public:
    XMLAssociation(Association *assoc, QXmlStreamWriter *writer,QXmlStreamReader *reader);
    ~XMLAssociation();
    void writeAssociation();

private:
    Association *m_assoc;
    QXmlStreamWriter *m_writer;
    QXmlStreamReader *m_reader;

};

#endif // XMLASSOCIATION_H
