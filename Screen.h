#pragma once
#include <list>
#include <vector>
#include <iostream>
#include "Tetromino.h"

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

	void operator<<(Tetromino tetro);
};