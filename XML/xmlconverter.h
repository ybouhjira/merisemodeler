#ifndef XMLCONVERTER_H
#define XMLCONVERTER_H

#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include "entity.h"
#include "association.h"

class XmlConverter
{
public:
    XmlConverter(QXmlStreamWriter *writer,QXmlStreamReader *reader);
    ~XmlConverter();
    void generateXml(Entity *entity);
private:
    QXmlStreamWriter *m_writer;
    QXmlStreamReader *m_reader;

};

#endif // XMLCONVERTER_H
