#ifndef SCREEN_H
#define SCREEN_H

#include <list>
#include <vector>
#include <iostream>
#include "Tetromino.h"
#include <cstring>

#if defined(_WIN32) || defined(_WIN64)
#include <Windows.h>
#endif


class Grid {
private:
	using Iterator = std::list<std::vector<int>*>::iterator;
	using R_Iterator = std::list<std::vector<int>*>::reverse_iterator;
	using Line = std::vector<int>;

	std::list<Line*> matrix;
	static Line* newLine();
	void del_line(Iterator temp);

	Iterator begin();
	Iterator end();
	R_Iterator rbegin();
	R_Iterator rend();

public:
	using C_R_Iterator = std::list<std::vector<int>*>::const_reverse_iterator;
	using C_Iterator = std::list<std::vector<int>*>::const_iterator;

	Grid();
	Grid(const Grid& ref);
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