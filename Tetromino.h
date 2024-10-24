#ifndef TETROMINO_H
#define TETROMINO_H

#include "Square.h"

class Tetromino {
protected:
	Square* blocks;
	Square core;
	void moveCore(const int x, const int y);
public:
	static const unsigned int nb_block;
	Tetromino();
	~Tetromino();
	virtual void rotateL();
	virtual void rotateR();
	bool down;
	const Square operator[](const unsigned int index) const;
	void moveX(const int dX);
	void moveY(const int dY);
	void setCore(const int x, const int y);
	Tetromino& operator=(const Tetromino& tetro);
	int yMax() const;
	int yMin() const;
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