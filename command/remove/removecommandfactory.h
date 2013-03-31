#ifndef REMOVECOMMANDFACTORY_H
#define REMOVECOMMANDFACTORY_H

#include "../namespace.h"
#include "model/namespace.h"
#include "graphic/namespace.h"

class QGraphicsItem;
class QGraphicsScene;

/**
 * @brief La classe Command::RemoveCommandFactory est une fabrique abstraite
 * pour creer les commande de supression
 */
class Command::RemoveCommandFactory
{
public:
    /**
     * @brief Destructeur
     */
    virtual ~RemoveCommandFactory();

    /**
     * @brief Retourne une instance de cette classe
     * @param clickedItem element cliqué
     * @throws UnsupportedItemException si la supression de l'element n'est pas
     * supporté par l'application
     */
    static RemoveCommandFactory* createFactory(QGraphicsItem *clickedItem);

    /**
     * @brief Retourne une instance de Command::RemoveCommand
     * @param model model MCD
     * @param scene Scene representatif du model MCD
     */
    virtual Command::RemoveCommand* create(
            Graphic::Object* object,
            Model::McdModel* model,
            QGraphicsScene* scene) = 0;

protected:
    RemoveCommandFactory(){}
};

#endif // REMOVECOMMANDFACTORY_H
