#ifndef TETROMINO_H
#define TETROMINO_H

#include "Square.h"

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

class Tetromino {
protected:
	Square* blocks;
	Square core;
	void setCore(int x, int y);
public:
	Tetromino();
	~Tetromino();
	virtual void rotateL();
	virtual void rotateR();
	bool down;
};

#endif

