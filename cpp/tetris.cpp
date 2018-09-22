#include "tetris.h"
#include <windows.h>
#pragma once

void start(){
    startUp();
    play();
}

void play(){
  GameState state = initialize(20,10);
  GameState backup;
  bool playing = true;
  int score = 0;
  char action;
  while(playing){
    showGameState(state);
    showScore(score);
    action = getch();
    backup = copyGameState(state);

    if(action == 's'){//MOVE DOWN
      state = moveDown(state);
      if(isOver(state)){
        state = backup;
        state = appendPiece(state);
        state.currentTetromino = copyTetro(state.nextTetromino);
        state.nextTetromino = getRandomTetromino();
      }
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
    else{//DEFAULT MOVE DOWN
      state = moveDown(state);
      if(isOver(state)){
        state = backup;
        state = appendPiece(state);
        state.currentTetromino = copyTetro(state.nextTetromino);
        state.nextTetromino = getRandomTetromino();
      }

    }
    while ((action = getch()) != -1);
    Sleep(500);


  }
}

void endGame(){
  endwin();
}
