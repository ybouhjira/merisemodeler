#ifndef UNSOPPORTEDITEMEXCEPTION_H
#define UNSOPPORTEDITEMEXCEPTION_H

#include "../namespace.h"

// Qt
class QGraphicsItem;
// std
#include <exception>

class Command::UnsupportedItemException : public std::exception
{
public:
    explicit UnsupportedItemException(QGraphicsItem* item);

    /**
     * @brief Mutateur
     */
    void setItem(QGraphicsItem* item) ;

    /**
     * @brief Accesseur
     */
    QGraphicsItem* item() const ;

private:
    /**
     * @brief L'element qui a causé l'exception
     */
    QGraphicsItem* m_item;
};

#endif // UNSOPPORTEDITEMEXCEPTION_H
