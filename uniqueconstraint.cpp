#include "uniqueconstraint.h"

UniqueConstraint::UniqueConstraint(QList<Property *> properties)
    :MultiPropertyConstraint(properties)
{
}

UniqueConstraint::~UniqueConstraint() {

}
