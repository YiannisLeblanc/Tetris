#include <iostream>
#include "tetris_game.h"
using namespace std;

int main() {/*
	HideConsoleCursor();

	Tetromino* tetro = new TBar;
	tetro->setCore(4, 25);
	tetro->moveCore((*tetro)[2]);
	TBar tetro2;
	tetro2.setCore(4,10);

	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO ConsoleScreenBufferInfo;
	GetConsoleScreenBufferInfo(out, &ConsoleScreenBufferInfo);
	COORD cursor = ConsoleScreenBufferInfo.dwCursorPosition;
	Grid* matrix = new Grid(out, cursor);
	for (int i = 0;;i++) {
		cout << "\n"; 
		gridDisplay(*matrix);
		tetroDisplay(*tetro, out, cursor);
		Sleep(500);
		tetro->moveY(-1);
		tetro->rotateL();
	}*/
	return 0;
}