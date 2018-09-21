#pragma once

#include "point.h"
#include "tetromino.h"

struct GameState {
    int nlines, ncolumns;
    Point * activePoints;
    int qtdActivePoints;
    Tetromino currentTetromino;
    Tetromino nextTetromino;
    int score;
};

/**
 * Generate a empty game knowing the number of lines and columns
 * */
GameState initialize(int nlines, int ncolumns);

/**
 * Should say if in the current state there are no overlap between
 * active points and current Tetromino and if the points are
 * in a valid interval
 * */
bool isValidState(GameState state);

/**
 * Should generate the next state based in previous state and movement
 * */
GameState moveDown(GameState state);

GameState moveLeft(GameState state);
GameState moveRight(GameState state);
GameState rotateClockwise(GameState state);
GameState rotateAnticlockwise(GameState state);

/**
 * If it's is impossible to make a move with the current tetromino
 * */
bool isOver(GameState state);

/**
 * Should remove complete lines and update score
 * */
GameState simplify(GameState state);
