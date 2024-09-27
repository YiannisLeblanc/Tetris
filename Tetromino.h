#ifndef TETROMINO_H
#define TETROMINO_H

#include "Square.h"

class Screen;

class Tetromino {
protected:
	Square* blocks;
	Square core;
	void setCore(int x, int y);
public:
	static const int nb_block;
	Tetromino();
	~Tetromino();
	virtual void rotateL();
	virtual void rotateR();
	bool down;
	friend Screen& Screen::operator<<(Tetromino& tetro);
};

typedef enum {
	none,
	i,
	o,
	t,
	l,
	j,
	z,
	s
} Shape;
 
#endif

