#include "gamestate.h"

// interval of time in microseconds
const int intervalBetweenFrames = 500000; // (??)

/**
 * Make initial configurations of the terminal
 * */
void startUp();

GameState generateIntialState();

void showGameState(GameState state);

char getChar();

/**
 * Revert the terminal to his normal state
 * */
void ends();