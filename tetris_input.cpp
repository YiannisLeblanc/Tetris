#include "tetris_input.h"

static bool rotateR_prev = false;
static bool rotateL_prev = false;
static bool moveR_prev = false;
static bool moveL_prev = false;

bool rotateR() {
    bool input;
    input = (getchar() == ':' && !rotateR_prev);
    rotateR_prev = input;
    return input;
}

bool rotateR_hold()
{
    return false;
}

bool rotateL()
{
    return false;
}

bool rotateL_hold()
{
    return false;
}

bool moveL()
{
    return false;
}

bool moveL_hold()
{
    return false;
}

bool moveR()
{
    return false;
}

bool moveR_hold()
{
    return false;
}
