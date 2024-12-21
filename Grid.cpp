#include "Grid.h"
using namespace std;
typedef std::list<std::vector<int>*>::iterator Iterator;
typedef std::list<std::vector<int>*>::reverse_iterator R_Iterator;
typedef std::vector<int> Line;

const int Grid::NB_COL = 10;
const int Grid::NB_LINE = 20;

Line* Grid::newLine() {
	Line* newLine = new vector<int>(NB_LINE);
	for (int i = 0; i < NB_LINE; i++) {
		(*newLine)[i] = 0;
	}
	return newLine;
}

void Grid::line_display(const std::vector<int> line) {
	console_front();
	for (int i = 0; i < NB_COL; i++) {
		if (line[i]) {
			console_filled_cell();
		}
		else {
			console_empty_cell();
		}
	}
	console_end();
}

void Grid::line_display(const std::vector<int> line, const Tetromino tetro, const int yIndex) 
{
	console_front();
	bool block;
	for (int i = 0; i < NB_COL; i++) {
		if (line[i]) {
			console_filled_cell();
		}
		else {
			block = false;
			for (int j = 0; j < tetro.NB_BLOCK && !block; j++) {
				if (tetro[j].getY() == yIndex && tetro[j].getX() == i) {
					block = true;
				}
			}
			if (block) {
				console_filled_cell();
			}
			else {
				console_empty_cell();
			}
		}
	}
	console_end();
}

void Grid::frame_display(COORD& current) {
	COORD temp = current;
	SetConsoleCursorPosition(this->consoleOutput, temp);
	for (int i = 0; i < NB_LINE; i++) {
		console_front();
		for (int j = 0;  j < NB_COL; j++) {
			cout << "  ";
		}
		console_end();
		cout << endl;
		temp.Y++;
		SetConsoleCursorPosition(this->consoleOutput, temp);
	}
	console_last_line_display();
	current.X += 2;
}

void Grid::console_last_line_display() {
	console_front();
	for (int i = 0; i < NB_COL; i++) cout << "==";
	console_end();
}

void Grid::console_front() {
	cout << "<!";
}

void Grid::console_end() {
	cout << "!>" << endl;
}

void Grid::console_filled_cell() {
	cout << "[]";
}

void Grid::console_empty_cell() {
	cout << " .";
}

R_Iterator Grid::console_line_display(const int L2, const int L1) const {
	if (L2 >= NB_LINE or L1 >= NB_LINE) return this->matrix->rbegin();
	
	unsigned int index = NB_LINE-1;
	R_Iterator temp;
	for (temp = this->matrix->rbegin(); index > L2 && temp != this->matrix->rend(); index--) {
		temp++;
	}
	for (; temp != this->matrix->rend() && index >= L1; temp++) {
		Grid::line_display(**temp);
		index--;
	}
	return temp;
}

void Grid::console_line_display_to_end(std::list<std::vector<int>*>::reverse_iterator temp) const {
	for (; temp != this->matrix->rend(); temp++) {
		line_display(**temp);
	}
}

Grid::Grid()/* : cnslFrm("<!", "!>", "==")*/ {
	matrix = new list<vector<int>*>;
	for (int i = 0; i < NB_LINE; i++) {
		matrix->push_back(newLine());
	}
}

Grid::Grid(HANDLE consoleOutput, COORD& cursorPosition) : Grid() {
	this->consoleOutput = consoleOutput;
	if (cursorPosition.X < 0 && cursorPosition.Y < 0) {
		cursorPosition.X = 0;
		cursorPosition.Y = 0;
	}
	frame_display(cursorPosition);
	this->cursorPosition = cursorPosition;
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
	for (int i = 0; i < NB_COL && full; i++) {
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

void Grid::console_display() const {
	this->console_line_display(NB_LINE - 1, 0);
	console_last_line_display();
}

void Grid::console_display(const Tetromino tetro) const {
	int start = tetro.yMax();
	int end = tetro.yMin();
	R_Iterator temp = this->console_line_display(NB_LINE - 1, start+1);
	for (int i = start; i > (end - 1) && temp != this->matrix->rend(); i--) {
		line_display(**temp, tetro, i);
		temp++;
	}
	console_line_display_to_end(temp);
	console_last_line_display();
}

void Grid::basic_line_display(const std::vector<int> line) {
	for (int i = 0; i < NB_COL; i++) {
		if (line[i]) {
			cout << "[]";
		}
		else {
			cout << " .";
		}
	}
}

void Grid::better_display() const {
	COORD cursPosTemp = this->cursorPosition;

	R_Iterator temp = this->matrix->rbegin();
	for (; temp != this->matrix->rend(); temp++) {
		SetConsoleCursorPosition(this->consoleOutput, cursPosTemp);
		Grid::basic_line_display(**temp);
		cursPosTemp.Y++;

	}
}

/*void Frame::strAssign(char* destination, const char* source) {
	if (destination != nullptr) {
		delete(destination);
	}
	destination = new char[strlen(source)];
	strcpy(destination, source);
}

Frame::Frame() {
	this->front = nullptr;
	this->end = nullptr;
	this->border = nullptr;
}

Frame::Frame(const char* front, const char* end, const char* border) {
	this->front = new char[strlen(front)];
	this->end = new char[strlen(end)];
	this->border = new char[strlen(border)];

	strcpy(this->front, front);
	strcpy(this->end, end);
	strcpy(this->border, border);
}

Frame::Frame(Frame& srcFrame) : Frame::Frame(srcFrame.front, srcFrame.end, srcFrame.border) {}

Frame::~Frame() {
	delete(this->front);
	delete(this->end);
	delete(this->border);
}

void Frame::setFront(const char* newFront) {
	strAssign(this->front, newFront);
}

void Frame::setEndt(const char* newEnd) {
	strAssign(this->end, newEnd);
}

void Frame::setBorder(const char* newBorder) {
	strAssign(this->border, newBorder);
}
*/