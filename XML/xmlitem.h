#ifndef XMLITEM_H
#define XMLITEM_H

#include "item.h"
#include "type.h"
#include "property.h"
#include <QXmlStreamReader>
#include <QXmlStreamWriter>

class XMLItem{
public:
    XMLItem(Item *item, QXmlStreamWriter *writer,QXmlStreamReader *reader);
    virtual ~XMLItem();
    void WriteItem();
    Item* ReadItem();
    void writeProperties(QList<Property*> properties, const QString &name);
    QList<Property*> readProperties();
private:
    Item* m_item;
    QXmlStreamWriter *m_writer;
    QXmlStreamReader *m_reader;

};


#endif // XMLITEM_H
