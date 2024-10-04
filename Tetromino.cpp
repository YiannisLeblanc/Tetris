#include "Tetromino.h"

const unsigned int Tetromino::nb_block = 4;

void Tetromino::setCore(int x, int y) {
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

const Square Tetromino::operator[](unsigned int index) const {
	if (index>=Tetromino::nb_block) return Square();

	return this->blocks[index] + this->core;
}


