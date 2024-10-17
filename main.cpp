#include <iostream>
#include "tetris_input.h"
#include "Grid.h"
#include "TBlock.h"
#include <windows.h>
using namespace std;

int main() {
	Grid* matrix = new Grid;
	Tetromino* tetro = new TBlock;
	tetro->moveX(3);
	tetro->moveY(4);
	*matrix << *tetro;
	matrix->console_display();
	cout << "\n";
	tetro->rotateR();
	tetro->moveX(5);
	*matrix << *tetro;
	matrix->console_display();
	return 0;
}