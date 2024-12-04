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
	static const int nb_line;
	static const int nb_col;
	std::list<std::vector<int>*>::reverse_iterator console_line_display(const int L2, const int L1) const;
	void console_line_display_to_end(std::list<std::vector<int>*>::reverse_iterator temp) const;
	static std::vector<int>* newLine();
	static void line_display(const std::vector<int> line);
	static void line_display(const std::vector<int> line, const Tetromino tetro, const int yIndex);
	static void console_last_line_display();
public:
	Grid();
	~Grid();

	static const int get_nb_line();
	static const int get_nb_col();

	void del_line(std::list<std::vector<int>*>::iterator temp);
	static bool isFull(const std::list<std::vector<int>*>::iterator temp);
	Grid& operator<<(Tetromino& tetro);
	void console_display() const;
	void console_display(const Tetromino tetro) const;
};

#endif