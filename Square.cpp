#include "Square.h"

int Square::getX() const {
    return this->x;
}

int Square::getY() const {
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

Square::Square(int x, int y) {
    this->set(x, y);
}

Square::Square() {
    this->set(0, 0);
}

Square& Square::operator=(const Square& square) {
    this->set(square.getX(), square.getY());
    return *this;
}

Square Square::operator+(const Square square) const {
    Square result(this->getX() + square.getX(), this->getY() + square.getY());
    return result;
}

Square Square::operator-(const Square square) const {
    Square result(this->getX() - square.getX(), this->getY() - square.getY());
    return result;
}

Square& Square::operator+=(const Square square) {
    *this = *this + square;
    return *this;
}

Square& Square::operator-=(const Square square) {
    *this = *this - square;
    return *this;
}
