#include "Grid.h"

using namespace std;
typedef list<vector<int>*>::iterator Iterator;
typedef list<vector<int>*>::reverse_iterator R_Iterator;
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
	for (int i = 0; i < Grid::nb_line; i++) {
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
		if (!testedLine[i]) {
			full = false;
		}
	}
	return full;
}

Grid& Grid::operator<<(Tetromino& tetro) {
	Iterator temp = matrix->begin();
	int index = 0;
	Square tempSquare;
	for (unsigned int i = 0; i < Tetromino::nb_block; i++) {
		tempSquare = tetro[i];
		if (tempSquare.getY() < Grid::get_nb_line() and tempSquare.getY() >= 0) {
			if (index < tempSquare.getY()) {
				for (; index < tempSquare.getY(); index++) {
					temp++;
				}
			}
			else {
				for (; index > tempSquare.getY(); index--) {
					temp--;
				}
			}
		}
		if (tempSquare.getX() < Grid::get_nb_col() && (tempSquare.getX() >= 0)) {
			(**temp)[tempSquare.getX()] = 1; 
		}
	}
	return *this;
}

void Grid::console_display() {
	for (R_Iterator temp = this->matrix->rbegin(); temp != this->matrix->rend(); temp++) {
		cout << "<!";
		for (int i = 0; i < Grid::get_nb_col(); i++) {
			if ((**temp)[i]) {
				cout << "[]";
			}
			else {
				cout << " .";
			}
		}
		cout << "!>" << endl;
	}
	cout << "<!";
	for (int i = 0; i < Grid::get_nb_col(); i++) cout << "==";
	cout << "!>" << endl;
}

void Grid::console_display(Tetromino tetro) {

}
