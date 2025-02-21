#ifndef TETRIS_GAME_H
#define TETRIS_GAME_H

#include "Grid.h"
#include "tetris_input.h"
#include "derived_Tetromino.h"

void HideConsoleCursor();
COORD GetCursorPosition();
bool setCursorPosition();

/*
  Display functions
*/
void gridDisplay(const Grid grid, const HANDLE out, const COORD cursor);
void displayGridFrame(HANDLE out, COORD current);
void tetroDisplay(Tetromino tetro,HANDLE out, COORD cursor);
#endif