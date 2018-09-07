#include "point.h"

/**
 * Defines a piece of tetris 
 * points[0] should be the center of mass of the piece
 * https://tetris.wiki/Tetromino
 * */
struct Tetromino{
    Point points[4];
};

Tetromino I;
Tetromino O;
Tetromino T;
Tetromino S;
Tetromino Z;
Tetromino J;
Tetromino L;

void setupTetrominos();

Tetromino moveDown(Tetromino tetromino);
Tetromino moveLeft(Tetromino tetromino);
Tetromino moveRight(Tetromino tetromino);

Tetromino rotateClockwise(Tetromino tetromino);

Tetromino rotateAnticlockwise(Tetromino tetromino);
