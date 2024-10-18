#include "Grid.h"
using namespace std;
typedef std::list<std::vector<int>*>::iterator Iterator;
typedef std::list<std::vector<int>*>::reverse_iterator R_Iterator;
typedef std::vector<int> Line;

const int Grid::nb_col = 10;
const int Grid::nb_line = 20;

Line* Grid::newLine() {
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

void Grid::console_line_display(unsigned int L2, unsigned int L1) {
	if (L2 >= Grid::get_nb_line() or L1 >= Grid::get_nb_line()) return;
	
	unsigned int index = Grid::get_nb_line()-1;
	R_Iterator temp;
	for (temp = this->matrix->rbegin(); index > L2 && temp != this->matrix->rend(); index--) {
		temp++;
	}
	for (; temp != this->matrix->rend() && index >= L1; temp++) {
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
		index--;
	}
}

Grid::Grid() {
	matrix = new list<vector<int>*>;
	for (int i = 0; i < Grid::nb_line; i++) {
		matrix->push_back(Grid::newLine());
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

void Grid::del_line(std::list<std::vector<int>*>::iterator temp) {
	delete(*temp);
	matrix->erase(temp);
	matrix->push_back(Grid::newLine());
}

bool Grid::isFull(std::list<std::vector<int>*>::iterator temp) {
	bool full = true;
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
	this->console_line_display(Grid::get_nb_line() - 1, 0);
	cout << "<!";
	for (int i = 0; i < Grid::get_nb_col(); i++) cout << "==";
	cout << "!>" << endl;
}

void Grid::console_display(Tetromino tetro) {
	
}
