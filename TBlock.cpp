#include "TBlock.h"
#pragma once

TBlock::TBlock() : Tetromino::Tetromino() {
	this->blocks[0].set(-1, 0);
	this->blocks[1].set(0, 0);
	this->blocks[2].set(1, 0);
	this->blocks[3].set(0, -1);
}