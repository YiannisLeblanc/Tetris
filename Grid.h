#ifndef SCREEN_H
#define SCREEN_H

#include <list>
#include <vector>
#include <iostream>
#include "Tetromino.h"

class Grid {
private:
	std::list<std::vector<int>*>* matrix;
	static const int nb_line;
	static const int nb_col;
public:
	Grid();
	~Grid();

	static const int get_nb_line();
	static const int get_nb_col();

	void del_line(int line);
	bool isFull(int line);
	Grid& operator<<(Tetromino& tetro);
	void console_display();
	void console_display(Tetromino tetro);
};

#endif