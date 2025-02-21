#ifndef SCREEN_H
#define SCREEN_H

#include <list>
#include <vector>
#include <iostream>
#include "Tetromino.h"
#include <Windows.h>
#include <cstring>


using C_R_Iterator = std::list<std::vector<int>*>::const_reverse_iterator;
using Line = std::vector<int>;
using C_Iterator = std::list<std::vector<int>*>::const_iterator;

class Grid {
private:
	using Iterator = std::list<std::vector<int>*>::iterator;
	using R_Iterator = std::list<std::vector<int>*>::reverse_iterator;

	std::list<Line*> matrix;
	static Line* newLine();
	void del_line(Iterator temp);

	Iterator begin();
	Iterator end();
	R_Iterator rbegin();
	R_Iterator rend();

public:
	Grid();
	~Grid();
	static const int NB_LINE;
	static const int NB_COL;

	static bool isFull(const Iterator temp);
	Grid& operator<<(Tetromino& tetro);
	C_Iterator begin() const;
	C_Iterator end() const;
	C_R_Iterator rbegin() const;
	C_R_Iterator rend() const;
};
#endif