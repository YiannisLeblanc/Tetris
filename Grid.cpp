#include "Grid.h"

using namespace std;
typedef list<vector<int>*>::iterator Iterator;
typedef vector<int> Line;

const int Grid::nb_col = 10;
const int Grid::nb_line = 20;

static Line* newLine() {
	Line* newLine = new vector<int>(Grid::get_nb_line());
	for (int i = 0; i < Grid::get_nb_line(); i++) {
		(*newLine)[i] = 0;
	}
	return newLine;
}

const int Grid::get_nb_line() {
	return Grid::nb_line;
}

const int Grid::get_nb_col() {
	return Grid::nb_col;
}

Grid::Grid() {
	matrix = new list<vector<int>*>;
	for (int i = 0; i < Grid::nb_col; i++) {
		matrix->push_back(newLine());
	}
}

Grid::~Grid() {
	Iterator temp;
	for (temp = matrix->begin(); temp != matrix->end(); temp++) {
		delete(*temp);
	}
	delete(*(++temp));
	delete(matrix);;
}

void Grid::del_line(int line) {
	Iterator temp = matrix->begin();
	for (int i = 0; i < line; i++) {
		temp++;
	}
	matrix->erase(temp);
	matrix->push_back(newLine());
}

bool Grid::isFull(int line) {
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

Grid& Grid::operator<<(Tetromino& tetro) {
	Iterator temp = matrix->begin();
	int index = 0;
	Square tempSquare;
	for (int i = 0; i < Tetromino::nb_block; i++) {
		tempSquare = tetro[i];
		if (index < tempSquare.getY()) {
			for (; index < tempSquare.getY(); index++) {
				temp++;
			}
		}
		else {
			for (; index > tempSquare.getY(); index++) {
				temp++;
			}
		}
		(**temp)[tempSquare.getX()] = 1;
	}
	return *this;
}

void Grid::console_display() {
	for (Iterator temp = this->matrix->end();; temp--);
}

void Grid::console_display(Tetromino tetro) {
}
