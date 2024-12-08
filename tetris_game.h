#ifndef TETRIS_GAME_H
#define TETRIS_GAME_H

#include "Grid.h"
#include "tetris_input.h"

void HideConsoleCursor();
void displayGridFrame();
COORD GetCursorPosition();
bool setCursorPosition();

#endif