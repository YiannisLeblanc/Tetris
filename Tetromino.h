#ifndef TETROMINO_H
#define TETROMINO_H

typedef enum {
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
	Shape type;
public:
	Tetromino(Shape type);
	~Tetromino();
	int rotateL();
	int rotateR();
};

class Square {
public:
	int x;
	int y;
};

#endif

