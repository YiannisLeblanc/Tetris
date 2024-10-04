#ifndef TETROMINO_H
#define TETROMINO_H

#include "Square.h"

class Tetromino {
protected:
	Square* blocks;
	Square core;
	void setCore(int x, int y);
public:
	static const unsigned int nb_block;
	Tetromino();
	~Tetromino();
	virtual void rotateL();
	virtual void rotateR();
	bool down;
	const Square operator[](unsigned int index) const;
	void moveX(int dX);
	void moveY(int dY);
	Tetromino& operator=(const Tetromino& tetro);
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