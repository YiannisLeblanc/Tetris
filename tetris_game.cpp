#include "tetris_game.h"

COORD cursorPosition;
HANDLE consoleOutput;

void HideConsoleCursor() {
	CONSOLE_CURSOR_INFO cursorInfo;
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = 0;
	SetConsoleCursorInfo(out, &cursorInfo);
}

void displayGridFrame() {
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
	for (int i = 0; i < tetro.NB_BLOCK; i++) {
		temp.X = cursor.X+(2*tetro[i].getX());
		temp.Y = Grid::NB_LINE-tetro[i].getY()-1 + cursor.Y;
		SetConsoleCursorPosition(out, temp);
		Grid::console_filled_cell();
	}
}
