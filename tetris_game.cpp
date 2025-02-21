#include "tetris_game.h"
using namespace std;

COORD cursorPosition;
HANDLE consoleOutput;

void HideConsoleCursor() {
	CONSOLE_CURSOR_INFO cursorInfo;
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = 0;
	SetConsoleCursorInfo(out, &cursorInfo);
}

void displayGridFrame(HANDLE out, COORD current) {
	COORD temp = current;
	SetConsoleCursorPosition(out, temp);
	for (int i = 0; i < Grid::NB_LINE; i++) {
		cout << "<!";
		for (int j = 0; j < Grid::NB_COL; j++) {
			cout << "  ";
		}
		cout << "!>" << endl;
		cout << endl;
		temp.Y++;
		SetConsoleCursorPosition(out, temp);
	}
	cout << "<!";
	for (int i = 0; i < Grid::NB_COL; i++) cout << "==";
	cout << "!>" << endl;
	current.X += 2;
}

void gridDisplay(const Grid grid, const HANDLE out, const COORD cursor) {
	COORD cursPosTemp = cursor;

	Grid::C_R_Iterator temp = grid.rbegin();
	for (; temp != grid.rend(); temp++) {
		SetConsoleCursorPosition(out, cursPosTemp);
		for (int i = 0; i < Grid::NB_COL; i++) {
			if ((**temp)[i]) {
				cout << "[]";
			}
			else {
				cout << " .";
			}
		}
		cursPosTemp.Y++;

	}
}

COORD GetCursorPosition()
{
	return COORD();
}

bool setCursorPosition()
{
	return false;
}

void tetroDisplay(Tetromino tetro,HANDLE out, COORD cursor) {
	COORD temp;
	for (unsigned int i = 0; i < tetro.NB_BLOCK; i++) {
		temp.X = cursor.X+(2*tetro[i].getX());
		temp.Y = Grid::NB_LINE-tetro[i].getY()-1 + cursor.Y;
		SetConsoleCursorPosition(out, temp);
		cout << "[]";
	}
}
