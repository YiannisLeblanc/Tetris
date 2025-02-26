#include <iostream>
#include "tetris_game.h"
using namespace std;

int main() {
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
	Grid* matrix = new Grid();
	for (int i = 0;;i++) {
		cout << "\n"; 
		gridDisplay(*matrix, out, cursor);
		tetroDisplay(*tetro, out, cursor);
		//Sleep(500);
		Input::update();
		if (Input::down()) tetro->moveY(-1);
		if (Input::left()) tetro->moveX(-1);
		if (Input::right()) tetro->moveX(1);
		if (Input::rotR())tetro->rotateR();
		if (Input::rotL())tetro->rotateL();
	}
	return 0;
}