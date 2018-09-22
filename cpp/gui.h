#pragma once

#include "gamestate.h"

// interval of time in microseconds
const int intervalBetweenFrames = 500000; // (??)

/**
 * Make initial configurations of the terminal
 * */
void startUp();
void drawExtraInfo(GameState state, int score, int powerUpBar);
GameState generateIntialState();

void showGameState(GameState state, int score, int powerUpBar);

char getChar();
/**
 * Revert the terminal to his normal state
 * */
void rollback();
