#include "Square.h"

int Square::getX() {
    return this->x;
}

int Square::getY() {
    return this->y;
}

void Square::set(int x, int y) {
    this->setX(x);
    this->setY(y);
}

void Square::setX(int x) {
    this->x = x;
}

void Square::setY(int y) {
    this->y = y;
}

void Square::move(int deltaX, int deltaY) {
    this->moveX(deltaX);
    this->moveY(deltaY);
}

void Square::moveX(int deltaX) {
    this->x += deltaX;
}

void Square::moveY(int deltaY) {
    this->y += deltaY;
}
