#pragma once

#include <curses.h>

/**
 * Defines the constant to represent the colors in the game
 **/

const int EMPTY = 1;
const int RED_PAIR = 2;
const int BLUE_PAIR = 3;
const int GREEN_PAIR = 4;
const int YELLOW_PAIR = 5;
const int MAGENTA_PAIR = 6;
const int CYAN_PAIR = 7;
const int WHITE_PAIR = 8;

void setupColors();