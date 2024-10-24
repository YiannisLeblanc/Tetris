#include "Tetromino.h"

const unsigned int Tetromino::nb_block = 4;

void Tetromino::moveCore(const int x, const int y) {
	for (int i = 0; i < Tetromino::nb_block; i++) {
		this->blocks[i].move(this->core.getX() - x, this->core.getY() - y);
	}
}

Tetromino::Tetromino() {
	this->blocks = new Square[Tetromino::nb_block];
	this->core.set(0, 0);
	down = false;
}

Tetromino::~Tetromino() {
	delete(this->blocks);
}

void Tetromino::rotateL() {
	for (int i = 0; i < Tetromino::nb_block; i++) {
		this->blocks[i].set(-this->blocks[i].getY(),this->blocks[i].getX());
	}
}

void Tetromino::rotateR() {
	for (int i = 0; i < Tetromino::nb_block; i++) {
		this->blocks[i].set(this->blocks[i].getY(), -this->blocks[i].getX());
	}
}

const Square Tetromino::operator[](const unsigned int index) const {
	if (index>=Tetromino::nb_block) return Square();

	return this->blocks[index] + this->core;
}

void Tetromino::moveY(const int dY) {
	this->core.moveY(dY);
}

void Tetromino::setCore(const int x, const int y) {
	this->core.set(x, y);
}

void Tetromino::moveX(const int dX) {
	this->core.moveX(dX);
}

Tetromino& Tetromino::operator=(const Tetromino& tetro) {
	for (int i = 0; i < Tetromino::nb_block; i++) {
		this->blocks[i] = tetro[i] - this->core;
	}
	return *this;
}

int Tetromino::yMax() const {
	int max = (*this)[0].getY();
	int temp;
	for (int i = 1; i < Tetromino::nb_block; i++) {
		temp = (*this)[i].getY();
		if (temp > max) {
			max = temp;
		}
	}
	return max;
}

int Tetromino::yMin() const {
	int min = (*this)[0].getY();
	int temp;
	for (int i = 1; i < Tetromino::nb_block; i++) {
		temp = (*this)[i].getY();
		if (temp < min) {
			min = temp;
		}
	}
	return min;
}
