#ifndef SCREEN_H
#define SCREEN_H

#include <list>
#include <vector>
#include <iostream>
#include "Tetromino.h"
#include <Windows.h>

class Grid {
private:
	std::list<std::vector<int>*>* matrix;
	std::list<std::vector<int>*>::reverse_iterator console_line_display(const int L2, const int L1) const;
	void console_line_display_to_end(std::list<std::vector<int>*>::reverse_iterator temp) const;
	static std::vector<int>* newLine();
	static void line_display(const std::vector<int> line);
	static void line_display(const std::vector<int> line, const Tetromino tetro, const int yIndex);
	static void console_last_line_display();
	static void console_front();
	static void console_end();
	static void console_filled_cell();
	static void console_empty_cell();
public:
	Grid();
	~Grid();

	static const int NB_LINE;
	static const int NB_COL;

	void del_line(std::list<std::vector<int>*>::iterator temp);
	static bool isFull(const std::list<std::vector<int>*>::iterator temp);
	Grid& operator<<(Tetromino& tetro);
	void console_display() const;
	void console_display(const Tetromino tetro) const;

	static void basic_line_display(const std::vector<int> line);
	
	void better_display(const COORD cursorPoisition, const HANDLE consoleOutput) const;
};

#endif