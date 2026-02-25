#ifndef TETRIS_INPUT_H
#define TETRIS_INPUT_H

#include <stdio.h>

#if defined(_WIN32) || defined(_WIN64)
#include <dinput.h>
#include <conio.h>
#endif

class Input {
private:
	enum Inputs {
	nullFlag = 0,
	upFlag = 1 << 0,
	downFlag = 1 << 1,
	leftFlag = 1 << 2,
	rightFlag = 1 << 3,
	rotLFlag = 1 << 4,
	rotRFlag = 1 << 5
	};
	static Inputs flag;
public:
	static void update();
	static bool up();
	static bool down();
	static bool left();
	static bool right();
	static bool rotL();
	static bool rotR();
	
	
};

#endif	