#include "../headers/entity.h"

Entity::Entity(QString imagePath, GameMap *gameMap, QObject *parent) : QObject(parent), QGraphicsPixmapItem()
{
    this->gameMap = gameMap;
    image = QPixmap(imagePath).scaled(SIZE, SIZE);
    setPixmap(image);
    isDead = false;
}

bool Entity::isMovePossible(std::string direction)
{
    int cellValue = 0;
    if (direction == "right")
    {
        cellValue = gameMap->getCellValue(posX, posY + 1);
    }
    if (direction == "left")
    {
        cellValue = gameMap->getCellValue(posX, posY - 1);
    }
    if (direction == "up")
    {
        cellValue = gameMap->getCellValue(posX - 1, posY);
    }
    if (direction == "down")
    {
        cellValue = gameMap->getCellValue(posX + 1, posY);
    }
    if (cellValue > 0 || cellValue == -1){
        return true;
    }

    return false;
}
