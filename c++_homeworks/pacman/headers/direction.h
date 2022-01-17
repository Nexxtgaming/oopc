#pragma once
#include <iostream>

struct Vector2
{
    int x;
    int y;
};

class Direction
{
private:
    std::string directionString;
    Vector2 vector2;
    void setVector();

public:
    Direction(std::string directionString = "up");
    Vector2 getVector();
    std::string getReverseDirection();
    std::string getDirString();
};
