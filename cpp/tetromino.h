#pragma once
#include "point.h"

/**
 * Defines a piece of tetris
 * points[0] should be the center of mass of the piece
 * https://tetris.wiki/Tetromino
 * */
struct Tetromino{
    Point points[4];
};

const int T = 1;
const int Z = 2;
const int I = 3;
const int L = 4;
const int J = 5;
const int S = 6;
const int O = 7;

Tetromino moveDown(Tetromino tetromino);
Tetromino moveLeft(Tetromino tetromino);
Tetromino moveRight(Tetromino tetromino);

Tetromino rotateClockwise(Tetromino tetromino);

Tetromino rotateAnticlockwise(Tetromino tetromino);
Tetromino copyTetro(Tetromino tetromino);
Tetromino getRandomTetromino();
