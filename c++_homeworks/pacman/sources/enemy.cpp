#include "../headers/enemy.h"

Enemy::Enemy(QString imagePath, std::string name, Pacman *player) : Entity(imagePath, player->gameMap)
{
    this->name = name;
    this->player = player;
    posX = 13;
    initValues();
    std::vector<Direction> possibleDirections = getPossibleDirections();
    approachFrom = possibleDirections[0].getReverseDirection();
    srand(time(NULL));
}

std::vector<Direction> Enemy::getPossibleDirections()
{
    std::vector<Direction> possibleDirectionsList;
    std::string allDirections[] = {"up", "right", "down", "left"};
    for (std::string direction : allDirections)
    {
        if (isMovePossible(direction))
        {
            possibleDirectionsList.push_back(Direction(direction));
        }
    }
    return possibleDirectionsList;
}

void Enemy::eatPlayer(int mode)
{
    int playerPosX = player->posX;
    int playerPosY = player->posY;
    if (this->posY == playerPosY && this->posX == playerPosX)
    {
        if (mode != 3)
        {
            player->isDead = true;
        }
        else
        {
            isDead = true;
        }
    }
}
Direction Enemy::chooseDirection(std::vector<Direction> directions, int mode)
{
    Direction nextDirection;
    double minDistance = BOARD_X * BOARD_Y;
    Vector2 target;
    if (mode == 1)
        target = chaseTarget;
    if (mode == 2)
        target = scatterTarget;
    Vector2 vectorToTarget;
    vectorToTarget.x = player->posX - posX;
    vectorToTarget.y = player->posY - posY;
    double currentDistance = sqrt(pow(vectorToTarget.x, 2) + pow(vectorToTarget.y, 2));

    if (mode == 3 || (isOrange && (currentDistance > 8 * SIZE)))
    {
        int randChoice = rand() % directions.size();
        std::cout<<randChoice<<std::endl;
        nextDirection = directions[randChoice];
        
    }
    else
    {
        for (Direction direction : directions)
        {
            Vector2 moveVector = direction.getVector();
            Vector2 vectorToTarget;
            vectorToTarget.x = player->posX + target.x - posX + moveVector.x;
            vectorToTarget.y = player->posY + target.y - posY + moveVector.y;
            double distance = sqrt(pow(vectorToTarget.x, 2) + pow(vectorToTarget.y, 2));
            if (distance <= minDistance && direction.getDirString() != approachFrom.getDirString())
            {
                minDistance = distance;
                nextDirection = direction;
            }
        }
    }
    return nextDirection;
}
int Enemy::move(int mode, int timeElapsed)
{
    if (mode != 1 && timeElapsed > SCARED_DURATION)
    {
        mode = 1;
    }
    Vector2 nextMove;
    Direction nextDirection;
    std::vector<Direction> possibleDirections = getPossibleDirections();
    if (possibleDirections.size() == 1)
    {
        nextDirection = possibleDirections[0];
    }
    if (possibleDirections.size() == 2)
    {
        if (possibleDirections[0].getDirString() == approachFrom.getDirString())
        {
            nextDirection = possibleDirections[1];
        }else{
            nextDirection = possibleDirections[0];
        }
    }
    if (possibleDirections.size() > 2)
    {
        nextDirection = chooseDirection(possibleDirections, mode);
    }
    nextMove = nextDirection.getVector();
    posX += nextMove.x;
    posY += nextMove.y;
    approachFrom = nextDirection.getReverseDirection();
    overlap();
    setPos(MARGIN_X + posY * SIZE, MARGIN_Y + posX * SIZE);
    return mode;
}

void Enemy::overlap(){
    
    if(posY < 0) posY = BOARD_Y -1;
    if(posY == BOARD_Y) posY = 0;
    if(posX < 0 ) posX = BOARD_X - 1;
    if(posX == BOARD_X) posX = 0;
}

void Enemy::initValues()
{
    int firstSpawnPos = 10;
    if (name == "inky")
    {
        chaseTarget.x = 2 * player->direction.getVector().x;
        chaseTarget.y = 2 * player->direction.getVector().y;
        posY = firstSpawnPos;
        scatterTarget = {0, BOARD_Y - 1};
    }
    if (name == "blinky")
    {
        posY = firstSpawnPos + 1;
        chaseTarget = {0, 0};
        scatterTarget = {BOARD_X - 1, 0};
    }
    if (name == "clyde")
    {
        posY = firstSpawnPos + 2;
        isOrange = true;
        scatterTarget = {BOARD_X - 1, BOARD_Y - 1};
    }
    if (name == "pinky")
    {
        posY = firstSpawnPos + 3;
        chaseTarget.x = 4 * player->direction.getVector().x;
        chaseTarget.y = 4 * player->direction.getVector().y;

        scatterTarget = {0, 0};
    }
}

void Enemy::setPlayer(Pacman *player)
{
    this->player = player;
}