#include "../headers/enemy.h"

Enemy::Enemy(QString imagePath, std::string name) : Entity(imagePath)
{
    this->name = name;
    std::vector<Direction> possibleDirections = getPossibleDirections();
    approachFrom = possibleDirections[0].getReverseDirection();
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
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

void Enemy::eatPlayer()
{
    int playerPosX = gameManager->player->posX;
    int playerPosY = gameManager->player->posY;
    if (this->posY == playerPosY && this->posX == playerPosX)
    {
        if (gameManager->mode != 3)
        {
            gameManager->gameOver = true;
        }
        else
        {
            isDead = true;
        }
    }
}
Direction Enemy::chooseDirection(std::vector<Direction> directions)
{
    Direction nextDirection;
    double minDistance = BOARD_X * BOARD_Y;
    Vector2 target;
    if (gameManager->mode == 1)
        target = chaseTarget;
    if (gameManager->mode == 2)
        target = scatterTarget;

    if (gameManager->mode == 3)
    {
        srand(time(NULL));
        int randChoice = rand() % directions.size();
        nextDirection = directions[randChoice];
    }
    else
    {
        for (Direction direction : directions)
        {
            Vector2 moveVector = direction.getVector();
            Vector2 vectorToTarget;
            vectorToTarget.x = gameManager->player->posX + target.x - posX + moveVector.x;
            vectorToTarget.y = gameManager->player->posY + target.y - posY + moveVector.y;
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
void Enemy::move()
{
    if (gameManager->mode != 1 && gameManager->getTimeElapsed() > SCARED_DURATION)
    {
        gameManager->mode = 1;
    }
    eatPlayer();
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
        }
    }
    if (possibleDirections.size() > 2)
    {
        nextDirection = chooseDirection(possibleDirections);
    }
    nextMove = nextDirection.getVector();
    posX += nextMove.x;
    posY += nextMove.y;
    approachFrom = nextDirection.getReverseDirection();
}