#include "Grid.h"
using namespace std;
const int Grid::NB_COL = 10;
const int Grid::NB_LINE = 20;

Grid::Line* Grid::newLine() {
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

Grid::Grid(const Grid& ref) : Grid::Grid() {
	Iterator temp = this->begin();
	C_Iterator refTemp = ref.begin();
	while ( temp != this->end() && refTemp != ref.end()) {
		for (unsigned int i = 0; i < ref.NB_COL && i < this->NB_COL; i++) {
			(**temp)[i] = (**refTemp)[i];
		}
		temp++;
		refTemp++;
	}
}

Grid::~Grid() {
	Iterator temp;
	for (temp = begin(); temp != end(); temp++) {
		delete(*temp);
	}
}

void Grid::del_line(Iterator temp) {
	delete(*temp);
	matrix.erase(temp);
	matrix.push_back(newLine());
}

Grid::Iterator Grid::begin() {
	return begin();
}

Grid::Iterator Grid::end() {
	return end();
}

Grid::R_Iterator Grid::rbegin() {
	return rbegin();
}

Grid::R_Iterator Grid::rend() {
	return rend();
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

Grid::C_Iterator Grid::begin() const {
	return matrix.begin();
}

Grid::C_Iterator Grid::end() const {
	return matrix.end();
}

Grid::C_R_Iterator Grid::rbegin() const {
	return matrix.rbegin();
}

Grid::C_R_Iterator Grid::rend() const {
	return matrix.rend();
}