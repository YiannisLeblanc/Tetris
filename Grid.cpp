#include "Grid.h"
using namespace std;
typedef std::list<std::vector<int>*>::iterator Iterator;
typedef std::list<std::vector<int>*>::reverse_iterator R_Iterator;
typedef std::vector<int> Line;

const int Grid::nb_col = 10;
const int Grid::nb_line = 20;

Line* Grid::newLine() {
	Line* newLine = new vector<int>(get_nb_line());
	for (int i = 0; i < get_nb_line(); i++) {
		(*newLine)[i] = 0;
	}
	return newLine;
}

void Grid::line_display(const std::vector<int> line) {
	cout << "<!";
	for (int i = 0; i < get_nb_col(); i++) {
		if (line[i]) {
			cout << "[]";
		}
		else {
			cout << " .";
		}
	}
	cout << "!>" << endl;
}

void Grid::line_display(const std::vector<int> line, const Tetromino tetro, const int yIndex) {
	cout << "<!";
	bool block;
	for (int i = 0; i < get_nb_col(); i++) {
		if (line[i]) {
			
				cout << "[]";
			
		}
		else {
			block = false;
			for (int j = 0; j < tetro.nb_block && !block; j++) {
				if (tetro[j].getY() == yIndex && tetro[j].getX() == i) {
					block = true;
				}
			}
			if (block) {
				cout << "[]";
			}
			else {
				cout << " .";
			}
		}
	}
	cout << "!>" << endl;
}

void Grid::console_last_line_display() {
	cout << "<!";
	for (int i = 0; i < get_nb_col(); i++) cout << "==";
	cout << "!>" << endl;
}

const int Grid::get_nb_line() {
	return nb_line;
}

const int Grid::get_nb_col() {
	return nb_col;
}

R_Iterator Grid::console_line_display(unsigned int L2, unsigned int L1) const {
	if (L2 >= Grid::get_nb_line() or L1 >= Grid::get_nb_line()) return this->matrix->rbegin();
	
	unsigned int index = Grid::get_nb_line()-1;
	R_Iterator temp;
	for (temp = this->matrix->rbegin(); index > L2 && temp != this->matrix->rend(); index--) {
		temp++;
	}
	for (; temp != this->matrix->rend() && index >= L1; temp++) {
		Grid::line_display(**temp);
		index--;
	}
	if (temp != this->matrix->rend()) {
		temp++;
	}
	return temp;
}

void Grid::console_line_display_to_end(std::list<std::vector<int>*>::reverse_iterator temp) const {
	for (; temp != this->matrix->rend(); temp++) {
		line_display(**temp);
	}
}

Grid::Grid() {
	matrix = new list<vector<int>*>;
	for (int i = 0; i < get_nb_line(); i++) {
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

void Grid::del_line(std::list<std::vector<int>*>::iterator temp) {
	delete(*temp);
	matrix->erase(temp);
	matrix->push_back(newLine());
}

bool Grid::isFull(const std::list<std::vector<int>*>::iterator temp) {
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
	for (unsigned int i = 0; i < tetro.nb_block; i++) {
		tempSquare = tetro[i];
		if (tempSquare.getY() < get_nb_line() and tempSquare.getY() >= 0) {
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
		if (tempSquare.getX() < get_nb_col() && (tempSquare.getX() >= 0)) {
			(**temp)[tempSquare.getX()] = 1; 
		}
	}
	return *this;
}

void Grid::console_display() const {
	this->console_line_display(get_nb_line() - 1, 0);
	console_last_line_display();
}

void Grid::console_display(const Tetromino tetro) const {
	int start = tetro.yMax();
	int end = tetro.yMin();
	R_Iterator temp = this->console_line_display(get_nb_line() - 1, start+1);
	for (int i = start; i > (end - 1) && temp != this->matrix->rend(); i--) {
		line_display(**temp, tetro, i);
		temp++;
	}
	console_line_display_to_end(temp);
	console_last_line_display();
}
