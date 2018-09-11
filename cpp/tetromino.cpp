#include "tetromino.h"

void setupTetrominos(){

}

Tetromino moveDown(Tetromino tetromino){
    Tetromino nextTetromino;
    Point newPoints[4];
    for(int i = 0; i < 4;i++){
      newPoints[i] = point.moveDown(tetromino.points[i]);
    }
    nextTetromino.points = newPoints;

    return nextTetromino;
}
Tetromino moveLeft(Tetromino tetromino){
  Tetromino nextTetromino;
  Point newPoints[4];
  for(int i = 0; i < 4;i++){
    newPoints[i] = point.moveLeft(tetromino.points[i]);
  }
  nextTetromino.points = newPoints;

  return nextTetromino;
}
Tetromino moveRight(Tetromino tetromino){
  Tetromino nextTetromino;
  Point newPoints[4];
  for(int i = 0; i < 4;i++){
    newPoints[i] = point.moveRight(tetromino.points[i]);
  }
  nextTetromino.points = newPoints;

  return nextTetromino;
}

Tetromino rotateClockwise(Tetromino tetromino){
  Tetromino nextTetromino;
  Point newPoints[4];
  newPoints[0] = tetromino.points[0];
  for(int i = 1; i < 4;i++){
    newPoints[i] = point.rotateClockwise(tetromino.points[0], tetromino.points[i]);
  }
  nextTetromino.points = newPoints;

  return nextTetromino;
}

Tetromino rotateAnticlockwise(Tetromino tetromino){
  Tetromino nextTetromino;
  Point newPoints[4];
  newPoints[0] = tetromino.points[0];
  for(int i = 1; i < 4;i++){
    newPoints[i] = point.rotateAnticlockwise(tetromino.points[0], tetromino.points[i]);
  }
  nextTetromino.points = newPoints;

  return nextTetromino;
}

Tetromino copyTetromino(Tetromino tetromino){
  Tetromino newTetromino;
  Point newPoints[4];
  for(int i = 0; i < 4; i++){
    newTetromino.points[i] = tetromino.points[i];
  }
  return newTetromino;
}

Tetromino getRandomTetromino(){
    Tetromino tetromino;
    
    return tetromino;
}
