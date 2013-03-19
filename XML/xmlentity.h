#ifndef XMLENTITY_H
#define XMLENTITY_H
#include "entity.h"
#include "xmlitem.h"
#include "uniqueconstraint.h"
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
/**
 * @brief class pour sauvgarder une entité sous forme des balises xml
 */
class XMLEntity
{
    //METHODS
public:
    /**
     * @brief Constructeur
     * @param entity
     * @param writer
     * @param reader
     */
    XMLEntity(Entity *entity, QXmlStreamWriter *writer, QXmlStreamReader *reader);

    /**
     * @brief destructeur
     */
    virtual ~XMLEntity();

    /**
     * @brief l'ecriture d'une entité
     */
    void writeEntity();

    /**
     * @brief la lecture d'une entité
     * @return
     */
    Entity* readEntity();

    /**
     * @brief Ecriture des propietés
     * @param properties : liste des propietés
     * @param name : nom de la balise qui contient des propietés
     */
    void writeProperties(QList<Property*> properties, const QString &name);

    //ATTRIBUTES
private:
    /**
      * @brief m_entity : l'entité qu'on veut la sauvegarder
      */
     Entity *m_entity;
     /**
      * @brief m_writer : Objet de l'ecriture du XML
      */
     QXmlStreamWriter *m_writer;
     /**
      * @brief m_reader : Objet de la lecture du XML
      */
     QXmlStreamReader *m_reader;


};

#endif // XMLENTITY_H
