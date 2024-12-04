#ifndef TETROMINO_H
#define TETROMINO_H

#include "Square.h"

class Tetromino {
protected:
	Square* blocks;
	Square core;
public:
	void moveCore(const int x, const int y);
	void moveCore(const Square square);
	static const unsigned int nb_block;
	Tetromino();
	Tetromino(const Tetromino& tetro);
	~Tetromino();
	virtual void rotateL();
	virtual void rotateR();
	bool down;
	const Square operator[](const unsigned int index) const;
	void moveX(const int dX);
	void moveY(const int dY);
	void setCore(const int x, const int y);
	void setCore(const Square square);
	Tetromino& operator=(const Tetromino& tetro);
	int yMax() const;
	int yMin() const;
};

enum class Shape{
	none,
	i,
	o,
	t,
	l,
	j,
	z,
	s
};

#endif