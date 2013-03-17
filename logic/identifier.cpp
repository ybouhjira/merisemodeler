#include "identifier.h"

Identifier::Identifier(QList<Property*> properties)
    : MultiPropertyConstraint(properties)
{
}

Identifier::~Identifier() {
}
