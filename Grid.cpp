#include "Grid.h"
using namespace std;
const int Grid::NB_COL = 10;
const int Grid::NB_LINE = 20;

Line* Grid::newLine() {
	Line* newLine = new vector<int>(NB_LINE);
	for (int i = 0; i < NB_LINE; i++) {
		(*newLine)[i] = 0;
	}
	return newLine;
}

Grid::Grid() : matrix() {
	for (int i = 0; i < NB_LINE; i++) {
		matrix.push_back(newLine());
	}
}

Grid::~Grid() {
	Iterator temp;
	for (temp = matrix.begin(); temp != matrix.end(); temp++) {
		delete(*temp);
	}
}

void Grid::del_line(Iterator temp) {
	delete(*temp);
	matrix.erase(temp);
	matrix.push_back(newLine());
}

Grid::Iterator Grid::begin() {
	return matrix.begin();
}

Grid::Iterator Grid::end() {
	return matrix.end();
}

Grid::R_Iterator Grid::rbegin() {
	return matrix.rbegin();
}

Grid::R_Iterator Grid::rend() {
	return matrix.rend();
}

bool Grid::isFull(const Iterator temp) {
	bool full = true;
	Line testedLine = **temp;
	for (int i = 0; i < NB_COL && full; i++) {
		if (!testedLine[i]) {
			full = false;
		}
	}
	return full;
}

Grid& Grid::operator<<(Tetromino& tetro) {
	Iterator temp = matrix.begin();
	int index = 0;
	Square tempSquare;
	for (unsigned int i = 0; i < tetro.NB_BLOCK; i++) {
		tempSquare = tetro[i];
		if (tempSquare.getY() < NB_LINE and tempSquare.getY() >= 0) {
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
		if (tempSquare.getX() < NB_COL && (tempSquare.getX() >= 0)) {
			(**temp)[tempSquare.getX()] = 1; 
		}
	}
	return *this;
}

C_Iterator Grid::begin() const {
	return matrix.begin();
}

C_Iterator Grid::end() const {
	return matrix.end();
}

C_R_Iterator Grid::rbegin() const {
	return matrix.rbegin();
}

C_R_Iterator Grid::rend() const {
	return matrix.rend();
}

