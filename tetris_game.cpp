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
