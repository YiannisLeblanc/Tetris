#ifndef TETRIS_CLASSES_H
#define TETRIS_CLASSES_H

#include "Square.h"
#include <vector>
#include <list>

class Screen {
private:std::list<std::vector<int>*>* matrix;
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