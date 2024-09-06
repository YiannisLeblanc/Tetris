#pragma once
#include <list>
#include <vector>
#include <iostream>

class Screen {
	static const int nb_line = 20;
	static const int nb_col = 10;
	std::list<std::vector<int>> matrix;
	Screen();
	void clear();
	bool isFull(int line);
};