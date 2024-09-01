#include "Tetromino.h"

void Tetromino::setCore(int x, int y) {
	for (int i = 0; i < 4; i++) {
		this->blocks[i].move(this->core.getX() - x, this->core.getY() - y);
	}
}

Tetromino::Tetromino(Shape type) {
	this->blocks = new Square[4];
	this->core.set(0, 0);
	down = false;
}

Tetromino::~Tetromino() {
	delete(this->blocks);
}

void Tetromino::rotateL() {
	for (int i = 0; i < 4; i++) {
		this->blocks[i].set(-this->blocks[i].getY(),this->blocks[i].getX());
	}
}

void Tetromino::rotateR() {
	for (int i = 0; i < 4; i++) {
		this->blocks[i].set(this->blocks[i].getY(), -this->blocks[i].getX());
	}
}
