#ifndef SCREEN_H
#define SCREEN_H

#include <list>
#include <vector>
#include <iostream>
#include "Tetromino.h"
#include <Windows.h>
#include <cstring>

class Grid {
private:
	std::list<std::vector<int>*>* matrix;
	std::list<std::vector<int>*>::reverse_iterator console_line_display(const int L2, const int L1) const;
	HANDLE consoleOutput;
	COORD cursorPosition;

	static std::vector<int>* newLine();
	void del_line(std::list<std::vector<int>*>::iterator temp);
	static void line_display(const std::vector<int> line);

	//Les fonctions bien caca tu connais
	void console_line_display_to_end(std::list<std::vector<int>*>::reverse_iterator temp) const;
	static void line_display(const std::vector<int> line, const Tetromino tetro, const int yIndex);

	void frame_display(COORD& current);
	static void console_last_line_display();
	static void console_front();
	static void console_end();
	static void console_empty_cell();
public:
	//Frame cnslFrm;
	Grid();
	Grid(HANDLE consoleOutput, COORD& cursorPosition);
	~Grid();

	static void console_filled_cell();
	static const int NB_LINE;
	static const int NB_COL;

	static bool isFull(const std::list<std::vector<int>*>::iterator temp);
	Grid& operator<<(Tetromino& tetro);
	void console_display() const;
	void console_display(const Tetromino tetro) const;

	static void basic_line_display(const std::vector<int> line);
	
	void better_display() const;
	
};

/*class Frame {
private:
	static void strAssign(char* destination, const char* source);
	public:
		char* front;
		char* end;
		char* border;
		Frame();
		Frame(const char* front, const char* end, const char* border);
		Frame(Frame& srcFrame);
		~Frame();
		void setFront(const char* newFront);
		void setEndt(const char* newEnd);
		void setBorder(const char* newBorder);
	};
*/
#endif