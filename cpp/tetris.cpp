#include "tetris.h"
#include <unistd.h>
#pragma once

void start(){
    play();
}

void play(){
  GameState state = initialize(20,10);
  GameState backup;
  bool playing = true;
  int score = 0;
  int powerUpBars = 0;
  char action;
  while(playing){
    showGameState(state,score, powerUpBars);
    action = getch();
    backup = copyGameState(state);

    if(action == 's'){//MOVE
      while(1){
      backup = copyGameState(state);
      state = moveDown(state);
      if(!isValidState(state))break;

      }
      state = backup;
      state = appendPiece(state);
      state = simplify(state,score,powerUpBars);
      state.currentTetromino = copyTetro(state.nextTetromino);
      state.nextTetromino = getRandomTetromino();


    }

    else if(action == 'w'){//ROTATE CLOCKWISE
      state = rotateClockwise(state);
      if(!isValidState(state)) state = backup;
    }
    else if(action == 'd'){//MOVE RIGHT
      state = moveRight(state);
      if(!isValidState(state)) state = backup;
    }
    else if(action == 'a'){//MOVE LEFT
      state = moveLeft(state);
      if(!isValidState(state)) state = backup;
    }
    else if(action == 'p' && powerUpBars >= 5){//POWER UP
      state.currentTetromino = copyTetro(state.nextTetromino);
      state.nextTetromino = getRandomTetromino();
      powerUpBars = 0;
      if(!isValidState(state)) break;
    }
    else{//DEFAULT MOVE DOWN
      state = moveDown(state);
      if(isOver(state)){
        state = backup;
        state = appendPiece(state);
        state = simplify(state,score,powerUpBars);
        state.currentTetromino = copyTetro(state.nextTetromino);
        state.nextTetromino = getRandomTetromino();
        if(!isValidState(state)) break;
      }

    }
    while ((action = getch()) != -1);
    usleep(150000);


  }
}

void endGame(){
}
