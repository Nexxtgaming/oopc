#include "entity.h"

bool Entity::isMovePossible(std::string direction)
{
   // if(direction == "right" && )
    return true;

}

Entity::Entity(QString imagePath, QObject *parent ) : QObject(parent), QGraphicsPixmapItem()
{
    setPixmap(QPixmap(imagePath));
}
