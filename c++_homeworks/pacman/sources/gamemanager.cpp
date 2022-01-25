#include "../headers/gamemanager.h"

GameManager::GameManager(QObject *parent) : QObject(parent)
{
    this->gameMap = new GameMap();
    mode = 1;
    this->player = new Pacman(gameMap);
    gameTimer = new GameTimer();
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(gameLoop()));
    timer->start(200);
    addEnemies();
}

void GameManager::addEnemies()
{
    std::cout<<"before"<<std::endl;
    enemies[0] = new Enemy("resources/blue-ghost.png", "inky", player);
    enemies[1] = new Enemy("resources/orange-ghost.png", "clyde", player);
    enemies[2] = new Enemy("resources/red-ghost.png", "blinky", player);
    enemies[3] = new Enemy("resources/white-ghost.png", "pinky", player);
}

bool GameManager::isGameOver()
{
    return gameOver;
}

void GameManager::drawGameMap(QGraphicsScene * scene){
    text = new QGraphicsTextItem();
    for(int i = 0; i < BOARD_X; i++){
        for(int j = 0; j < BOARD_Y; j++){
            int value = gameMap->getCellValue(i, j);
            Square * square = new Square(MARGIN_X + j * SIZE, MARGIN_Y + i * SIZE);
            square->setRect(square->getX(), square->getY(), SIZE, SIZE);
            scene->addItem(square);
            if(value == 0){
                square->setBrush(Qt::blue);
            }else{
                square->setBrush(Qt::black);
            }
            if(value == 2 || value == 3){
                bool isSpecial = value == 2 ? false : true;
                Point * newPoint = new Point(i, j, isSpecial);
                points.push_back(newPoint);
                newPoint->setPos(MARGIN_Y + newPoint->getY() * SIZE, newPoint->getX()* SIZE + MARGIN_X);
            }

        }
    }
    text->setX(0);
    text->setY(0);
    text->setDefaultTextColor(Qt::black);
    scene->addItem(text);
    for(Enemy * enemy : enemies){
        scene->addItem(enemy);
    }
}

void GameManager::updateScene(){
    for(int i = 0; i < BOARD_X; i++){
        for(int j = 0; j < BOARD_Y; j++){
            int value = gameMap->getCellValue(i, j);
            if(value == 1){
                for(Point * point : points){
                    if(point->getX() == i && point->getY() == j){
                        delete point;
                    }
                }
            }
        }
    }
    for(Enemy * enemy : enemies){
        if(enemy->isDead){
            delete enemy;
        }
    }
    
}

void GameManager::gameLoop(QGraphicsScene * scene)
{
    if(!player->isDead){
        for(Enemy * enemy : enemies){
            mode = enemy->move(mode, gameTimer->getTimeElapsed());
            enemy->eatPlayer(mode);
        }
        mode = player->getPoint(mode, *gameTimer);
        const char * textValue = "Points";
        text->setProperty(textValue, player->points);

        std::cout<<player->points<<std::endl;
        updateScene();



    }
    QList<QGraphicsItem*> L = scene->items();
    while (!L.empty()){
		scene->removeItem(L.first());
                delete L.first();
    }

}
