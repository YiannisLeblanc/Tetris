#include <iostream>
#include "tetris_game.h"
#include "Grid.h"
#include "derived_Tetromino.h"
#include <windows.h>
using namespace std;

int main() {
	Grid* matrix = new Grid;
	Tetromino* tetro = new TBar;
	tetro->setCore(4, 25);
	tetro->moveCore((*tetro)[2]);
	TBar tetro2;
	tetro2.setCore(4,10);

	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO ConsoleScreenBufferInfo;
	GetConsoleScreenBufferInfo(out, &ConsoleScreenBufferInfo);
	COORD cursor = ConsoleScreenBufferInfo.dwCursorPosition;
	for (int i = 0;;i++) {
		cout << "\n"; 
		matrix->better_display(cursor, out);
		Sleep(500);
		tetro->moveY(-1);
		tetro->rotateL();
		*matrix << tetro2;
	}
	return 0;
}