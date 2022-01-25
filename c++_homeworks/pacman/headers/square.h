#pragma once
#include <QGraphicsRectItem>
#include <cmath>
#include "config.h"

class Square : public QGraphicsRectItem {
  private:
	int x;
	int y;
  public:
	Square(int x, int y) : QGraphicsRectItem() {
		this->x = x;
		this->y = y;
	}
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
};