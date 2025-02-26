#include "tetris_input.h"

Input::Inputs Input::flag = nullFlag;

void Input::update() { // à adapter au fichier json
	char c = _getch();
	switch (c) {
	case 'z':
		flag = upFlag;
		break;
	case 's':
		flag = downFlag;
		break;
	case 'q':
		flag = leftFlag;
		break;
	case 'd':
		flag = rightFlag;
		break;
	case ',':
		flag = rotLFlag;
		break;
	case ';':
		flag = rotRFlag;
		break;
	default:
		flag = nullFlag;
		break;
	}
}

bool Input::up() {
	return flag & Inputs::upFlag;
}

bool Input::down() {
	return flag & Inputs::downFlag;
}

bool Input::left() {
	return flag & Inputs::leftFlag;
}

bool Input::right() {
	return flag & Inputs::rightFlag;
}

bool Input::rotL() {
	return flag & Inputs::rotLFlag;
}

bool Input::rotR() {
	return flag & Inputs::rotRFlag;
}
