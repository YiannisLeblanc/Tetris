#include <iostream>
#include "tetris_input.h"
#include "Grid.h"
#include "derived_Tetromino.h"
#include <windows.h>
using namespace std;

int main() {
	Grid* matrix = new Grid;
	Tetromino* tetro = new TBar;
	tetro->setCore(4, 25);
	tetro->moveCore((*tetro)[2]);
	matrix->console_display();
	Sleep(5000);
	for (int i = 0;;i++) {
		cout << "\n"; 
		matrix->console_display(*tetro);
		Sleep(500);
		tetro->moveY(-1);
		tetro->rotateL();
	}
	return 0;
}