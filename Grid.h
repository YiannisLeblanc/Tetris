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
	void console_line_display(unsigned int L2, unsigned int L1);
	static std::vector<int>* newLine();
public:
	Grid();
	~Grid();

	static const int get_nb_line();
	static const int get_nb_col();

	void del_line(std::list<std::vector<int>*>::iterator temp);
	static bool isFull(std::list<std::vector<int>*>::iterator temp);
	Grid& operator<<(Tetromino& tetro);
	void console_display();
	void console_display(Tetromino tetro);
};

#endif