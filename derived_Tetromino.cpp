#include "derived_Tetromino.h"

TBar::TBar() : Tetromino::Tetromino() {
	this->blocks[0].set(1, -1);
	this->blocks[1].set(0, 0);
	this->blocks[2].set(1, 0);
	this->blocks[3].set(2, 0);
}

IBar::IBar() : Tetromino::Tetromino() {
	this->blocks[0].set(-1, 0);
	this->blocks[1].set(0, 0);
	this->blocks[2].set(1, 0);
	this->blocks[3].set(2, 0);
}

OBar::OBar() : Tetromino::Tetromino() {
	this->blocks[0].set(0, 0);
	this->blocks[1].set(0, -1);
	this->blocks[2].set(1, 0);
	this->blocks[3].set(1, -1);
}

SBar::SBar() : Tetromino::Tetromino() {
	this->blocks[0].set(-1, 0);
	this->blocks[1].set(-1, 1);
	this->blocks[2].set(0, 1);
	this->blocks[3].set(1, 1);
}

ZBar::ZBar() : Tetromino::Tetromino() {
	this->blocks[0].set(0, 0);
	this->blocks[1].set(1, 0);
	this->blocks[2].set(1, -1);
	this->blocks[3].set(2, -1);
}

LBar::LBar() : Tetromino::Tetromino() {
	this->blocks[0].set(0, 0);
	this->blocks[1].set(-1, 0);
	this->blocks[2].set(1, 0);
	this->blocks[3].set(2, 0);
}

RBar::RBar() : Tetromino::Tetromino() {
	this->blocks[0].set(0, 0);
	this->blocks[1].set(1, 0);
	this->blocks[2].set(2, 0);
	this->blocks[3].set(2, -1);
}