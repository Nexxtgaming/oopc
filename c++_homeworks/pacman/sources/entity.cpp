#include "../headers/entity.h"

bool Entity::isMovePossible(std::string direction)
{
    int cellValue;
    if (direction == "right")
    {
        cellValue = gameManager->gameMap->getCellValue(posX, posY + 1);
    }
    if (direction == "left")
    {
        cellValue = gameManager->gameMap->getCellValue(posX, posY - 1);
    }
    if (direction == "up")
    {
        cellValue = gameManager->gameMap->getCellValue(posX - 1, posY);
    }
    if (direction == "down")
    {
        cellValue = gameManager->gameMap->getCellValue(posX + 1, posY);
    }
    if (cellValue)
        return true;
    return false;
}

Entity::Entity(QString imagePath, QObject *parent) : QObject(parent), QGraphicsPixmapItem()
{
    setPixmap(QPixmap(imagePath));
}
