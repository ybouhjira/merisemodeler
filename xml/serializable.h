#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H

#include "pugixml/pugixml.hpp"
using namespace pugi;

class Serializable
{
public:
    /**
     * @brief Constructeur de l'interface
     */
    Serializable(){}

    /**
     * @brief Destructeur de l'interface
     */
    virtual ~Serializable(){}

    /**
     * @brief Ecriture d'une noeud xml
     * @return
     */
    virtual xml_node toXml() const  = 0;

    /**
     * @brief lecture d'une noeud xml
     */
    virtual void fromXml() const = 0;
};

#endif // SERIALIZABLE_H
