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
private:
	Square* blocks;
	Square core;
protected:
	void setCore(int x, int y);
public:
	Tetromino(Shape type);
	~Tetromino();
	virtual void rotateL();
	virtual void rotateR();
	bool down;
};

#endif

