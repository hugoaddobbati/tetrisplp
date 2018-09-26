#pragma once

#include "gamestate.h"

// interval of time in microseconds
const int intervalBetweenFrames = 500000; // (??)
const char menuText[8][50]={" _______     _          _      ",
                            "|__   __|   | |        (_)     ",
                            "   | |  ___ | |_  _ __  _  ___ ",
                            "   | | / _ \\| __|| '__|| |/ __|",
                            "   | ||  __/| |_ | |   | |\\__ \\",
                            "   |_| \\___| \\__||_|   |_||___/",
                            "",
                            "Pressione S para comecar o jogo"};

/**
 * Make initial configurations of the terminal
 * */
void startUp();
void drawExtraInfo(GameState state, int score, int powerUpBar);
void showMenuOptions();
void showGameState(GameState state, int score, int powerUpBar);
void clearScreen();
char getChar();
/**
 * Revert the terminal to his normal state
 * */
void rollback();
