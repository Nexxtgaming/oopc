#include "../headers/direction.h"

direction::Direction(std::string directionString)
{
    this->directionString = directionString;
    setVector();
}

void Direction::setVector()
{
    this->vector2.x = 0;
    this->vector2.y = 0;
    if (directionString == "up")
    {
        this->vector2.x = -1;
    }
    else if (directionString == "right")
    {
        this->vector2.y = 1;
    }
    else if (directionString == "down")
    {
        this->vector2.x = 1;
    }
    else if (directionString == "left")
    {
        this->vector2.y = -1;
    }
}

Vector2 Direction::getVector()
{
    return this->vector2;
}

std::string Direction::getReverseDirection()
{
    if (directionString == "up")
        return "down";
    if (directionString == "right")
        return "left";
    if (directionString == "down")
        return "up";
    if (directionString == "left")
        return "right";
}

std::string Direction::getDirString()
{
    return directionString;
}