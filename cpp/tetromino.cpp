#include "tetromino.h"

void setupTetrominos(){
asd
}

Tetromino moveDown(Tetromino tetromino){
    Tetromino nextTetromino;
    for(int i = 0; i < 4;i++){
      nextTetromino.points[i] = point.moveDown(tetromino.points[i]);
    }

    return nextTetromino;
}
Tetromino moveLeft(Tetromino tetromino){
  Tetromino nextTetromino;
  for(int i = 0; i < 4;i++){
    nextTetromino.points[i] = point.moveLeft(tetromino.points[i]);
  }
  return nextTetromino;
}
Tetromino moveRight(Tetromino tetromino){asd
  Tetromino nextTetromino;
  for(int i = 0; i < 4;i++){
    nextTetromino.points[i] = point.moveRight(tetromino.points[i]);
  }

  return nextTetromino;
}

Tetromino rotateClockwise(Tetromino tetromino){
  Tetromino nextTetromino;
  nextTetromino.points[0] = tetromino.points[0];
  for(int i = 1; i < 4;i++){
    nextTetromino.points[i] = point.rotateClockwise(tetromino.points[0], tetromino.points[i]);
  }
  return nextTetromino;
}

Tetromino rotateAnticlockwise(Tetromino tetromino){
  Tetromino nextTetromino;
  Point newPoints[4];
  nextTetromino.points[0] = tetromino.points[0];
  for(int i = 1; i < 4;i++){
    nextTetromino.points[i] = point.rotateAnticlockwise(tetromino.points[0], tetromino.points[i]);
  }
  return nextTetromino;
}

Tetromino copyTetromino(Tetromino tetromino){
  Tetromino newTetromino;
  for(int i = 0; i < 4; i++){
    newTetromino.points[i] = tetromino.points[i];
  }
  return newTetromino;
}

Tetromino getRandomTetromino(){
    Tetromino tetromino;
    
    return tetromino;
}
