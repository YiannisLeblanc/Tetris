#include "Screen.h"
using namespace std;
typedef list<vector<int>*>::iterator Iterator;
typedef vector<int> Line;

const int Screen::nb_col = 10;
const int Screen::nb_line = 20;

static Line* newLine() {
	Line* newLine = new vector<int>(Screen::get_nb_line());
	for (int i = 0; i < Screen::get_nb_line(); i++) {
		(*newLine)[i] = 0;
	}
	return newLine;
}

const int Screen::get_nb_line() {
	return Screen::nb_line;
}

const int Screen::get_nb_col() {
	return Screen::nb_col;
}

Screen::Screen() {
	matrix = new list<vector<int>*>;
	for (int i = 0; i < Screen::nb_col; i++) {
		matrix->push_back(newLine());
	}
}

Screen::~Screen() {
	Iterator temp;
	for (temp = matrix->begin(); temp != matrix->end(); temp++) {
		delete(*temp);
	}
	delete(*(++temp));
	delete(matrix);;
}

void Screen::del_line(int line) {
	Iterator temp = matrix->begin();
	for (int i = 0; i < line; i++) {
		temp++;
	}
	matrix->erase(temp);
	matrix->push_back(newLine());
}

bool Screen::isFull(int line) {
	bool full = true;
	Iterator temp = matrix->begin();
	for (int i = 0; i < line; i++) {
		temp++;
	}
	Line testedLine = **temp;
	for (int i = 0; i < get_nb_col() && full; i++) {
		if (testedLine[i]) {
			full = false;
		}
	}
	return full;
}

Screen& Screen::operator<<(Tetromino& tetro) {
	return *this;
}