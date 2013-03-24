#include "removecommandfactory.h"
#include "graphic/entity.h"
#include "graphic/association.h"
#include "graphic/inheritencearrowobject.h"

using namespace Command;

RemoveCommandFactory* RemoveCommandFactory::createFactory (
        const QGraphicsItem *clickedItem)
{
    if(dynamic_cast<Graphic::Entity*>(clickedItem) != nullptr)
        return new EntityRemoveCommandFactory;
    else if(dynamic_cast<Graphic::Association*>(clickedItem) != nullptr)
        return new AssociationRemoveCommandFactory;
    else if(dynamic_cast<Graphic::InheritenceArrowObject*>(clickedItem) != nullptr)
        return new InheritenceRemoveCommandFactory;
    else
        throw new UnsopportedItemException(clickedItem);
}

RemoveCommandFactory::~RemoveCommandFactory() {

}
