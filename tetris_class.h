#ifndef TETRIS_CLASS_H
#define TETRIS_CLASS_H

#include <list>
#include <vector>
#include <iostream>
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

class Screen {
private:
	std::list<std::vector<int>*>* matrix;
	static const int nb_line;
	static const int nb_col;
public:
	Screen();
	~Screen();

	static const int get_nb_line();
	static const int get_nb_col();

	void del_line(int line);
	bool isFull(int line);
	Screen& operator<<(Tetromino& tetro);
};

#endif