#include <iostream>
#include "tetris_input.h"
#include "Grid.h"
#include "derived_Tetromino.h"
#include <windows.h>
using namespace std;

int main() {
	Grid* matrix = new Grid;
	Tetromino* tetro = new TBar;
	tetro->setCore(4, 5);
	cout << endl;
	for (;;) {
		matrix->console_display(*tetro);
		cout << "\n";
		Sleep(500);
		tetro->moveY(-1);
	}
	return 0;
}