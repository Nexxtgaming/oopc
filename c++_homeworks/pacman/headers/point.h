#pragma once
#include <QGraphicsPixmapItem>
#include <cmath>
#include "config.h"

class Point : public QGraphicsPixmapItem {
  private:
	int x;
	int y;
    bool isSpecial;
    int amount;
  public:
	Point(int x, int y, bool isSpecial) : QGraphicsPixmapItem() {
		this->x = x;
		this->y = y;
        if(isSpecial){
            amount = BIG_POINT;
            this->setPixmap(QPixmap("resources/point2.png").scaled(SIZE, SIZE));
        }else{
            amount = SMALL_POINT;
            this->setPixmap(QPixmap("resources/point1.png").scaled(SIZE, SIZE));

        }
	}
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
    int getAmount(){
        return amount;
    }
};