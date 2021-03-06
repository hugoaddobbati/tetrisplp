#include "tetromino.h"
#include "point.h"
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <math.h>
#include <chrono>
#include <random>

Tetromino moveDown(Tetromino tetromino){
    Tetromino nextTetromino;
    for(int i = 0; i < 4;i++){
      nextTetromino.points[i] = moveDown(tetromino.points[i]);
    }

    return nextTetromino;
}
Tetromino moveLeft(Tetromino tetromino){
  Tetromino nextTetromino;
  for(int i = 0; i < 4;i++){
    nextTetromino.points[i] = moveLeft(tetromino.points[i]);
  }
  return nextTetromino;
}
Tetromino moveRight(Tetromino tetromino){
  Tetromino nextTetromino;
  for(int i = 0; i < 4;i++){
    nextTetromino.points[i] = moveRight(tetromino.points[i]);
  }

  return nextTetromino;
}

Tetromino rotateClockwise(Tetromino tetromino){
  Tetromino nextTetromino;
  nextTetromino.points[0] = tetromino.points[0];
  for(int i = 1; i < 4;i++){
    nextTetromino.points[i] = rotateClockwise(tetromino.points[0], tetromino.points[i]);
  }
  return nextTetromino;
}

Tetromino rotateAnticlockwise(Tetromino tetromino){
  Tetromino nextTetromino;
  nextTetromino.points[0] = tetromino.points[0];
  for(int i = 1; i < 4;i++){
    nextTetromino.points[i] = rotateAnticlockwise(tetromino.points[0], tetromino.points[i]);
  }
  return nextTetromino;
}

Tetromino copyTetro(Tetromino tetromino){
  Tetromino newTetromino;
  for(int i = 0; i < 4; i++){
    newTetromino.points[i] = tetromino.points[i];
  }
  return newTetromino;
}

Tetromino getRandomTetromino(){
    Tetromino tetromino;
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 generator (seed);
    int tetrominoType = generator() % 7 + 1;

    if(tetrominoType == T){
      tetromino.points[0].x = 5;
      tetromino.points[0].y = 1;
      tetromino.points[0].color = T;
      tetromino.points[1].x = 4;
      tetromino.points[1].y = 1;
      tetromino.points[1].color = T;
      tetromino.points[2].x = 5;
      tetromino.points[2].y = 0;
      tetromino.points[2].color = T;
      tetromino.points[3].x = 6;
      tetromino.points[3].y = 1;
      tetromino.points[3].color = T;
    }
    else if(tetrominoType == Z){
      tetromino.points[0].x = 5;
      tetromino.points[0].y = 1;
      tetromino.points[0].color = Z;
      tetromino.points[1].x = 4;
      tetromino.points[1].y = 1;
      tetromino.points[1].color = Z;
      tetromino.points[2].x = 5;
      tetromino.points[2].y = 0;
      tetromino.points[2].color = Z;
      tetromino.points[3].x = 4;
      tetromino.points[3].y = 2;
      tetromino.points[3].color = Z;
    }
    else if(tetrominoType == I){
      tetromino.points[0].x = 5;
      tetromino.points[0].y = 1;
      tetromino.points[0].color = I;
      tetromino.points[1].x = 5;
      tetromino.points[1].y = 0;
      tetromino.points[1].color = I;
      tetromino.points[2].x = 5;
      tetromino.points[2].y = 2;
      tetromino.points[2].color = I;
      tetromino.points[3].x = 5;
      tetromino.points[3].y = 3;
      tetromino.points[3].color = I;
    }
    else if(tetrominoType == L){
      tetromino.points[0].x = 5;
      tetromino.points[0].y = 1;
      tetromino.points[0].color = L;
      tetromino.points[1].x = 6;
      tetromino.points[1].y = 0;
      tetromino.points[1].color = L;
      tetromino.points[2].x = 6;
      tetromino.points[2].y = 1;
      tetromino.points[2].color = L;
      tetromino.points[3].x = 4;
      tetromino.points[3].y = 1;
      tetromino.points[3].color = L;
    }
    else if(tetrominoType == J){
      tetromino.points[0].x = 5;
      tetromino.points[0].y = 1;
      tetromino.points[0].color = J;
      tetromino.points[1].x = 6;
      tetromino.points[1].y = 0;
      tetromino.points[1].color = J;
      tetromino.points[2].x = 5;
      tetromino.points[2].y = 0;
      tetromino.points[2].color = J;
      tetromino.points[3].x = 5;
      tetromino.points[3].y = 2;
      tetromino.points[3].color = J;
    }
    else if(tetrominoType == S){
      tetromino.points[0].x = 5;
      tetromino.points[0].y = 1;
      tetromino.points[0].color = S;
      tetromino.points[1].x = 6;
      tetromino.points[1].y = 0;
      tetromino.points[1].color = S;
      tetromino.points[2].x = 5;
      tetromino.points[2].y = 0;
      tetromino.points[2].color = S;
      tetromino.points[3].x = 4;
      tetromino.points[3].y = 1;
      tetromino.points[3].color = S;
    }
    else if(tetrominoType == O){
      tetromino.points[0].x = 4;
      tetromino.points[0].y = 0;
      tetromino.points[0].color = O;
      tetromino.points[1].x = 4;
      tetromino.points[1].y = 1;
      tetromino.points[1].color = O;
      tetromino.points[2].x = 5;
      tetromino.points[2].y = 0;
      tetromino.points[2].color = O;
      tetromino.points[3].x = 5;
      tetromino.points[3].y = 1;
      tetromino.points[3].color = O;
    }
    return tetromino;
}
