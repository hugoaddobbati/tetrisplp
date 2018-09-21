#pragma once

#include <curses.h>

/**
 * Defines the constant to represent the colors in the game
 **/

const int EMPTY = 0;
const int WHITE_PAIR = 1;
const int GREEN_PAIR = 2;
const int RED_PAIR = 3;
const int YELLOW_PAIR = 4;
const int MAGENTA_PAIR = 5;
const int BLUE_PAIR = 6;
const int CYAN_PAIR = 7;


void setupColors();
