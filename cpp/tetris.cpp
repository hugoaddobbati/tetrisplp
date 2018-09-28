#include "tetris.h"
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <fstream>
using namespace std;
#pragma once

void start(){
    play();
    srand(time(NULL));
    noecho();
}

void play(){
  GameState state = initialize(20,10);
  GameState backup;
  bool playing = true;
  int score = 0;
  int powerUpBars = 0;
  char action;
  bool notPressed = true;
  int counter = 0;
  showGameState(state,score, powerUpBars);
  while(playing){
    counter += 1;
    action = getch();
    backup = copyGameState(state);

    if(action == 's'){//MOVE
      counter = 0;
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
      if(isOver(state)){
        break;
      }
      showGameState(state,score, powerUpBars);


    }

    else if(action == 'w'){//ROTATE CLOCKWISE
      state = rotateClockwise(state);
      if(!isValidState(state)) state = backup;
      showGameState(state,score, powerUpBars);
    }
    else if(action == 'd'){//MOVE RIGHT
      state = moveRight(state);
      if(!isValidState(state)) state = backup;
      showGameState(state,score, powerUpBars);
    }
    else if(action == 'a'){//MOVE LEFT
      state = moveLeft(state);
      if(!isValidState(state)) state = backup;
      showGameState(state,score, powerUpBars);
    }
    else if(action == 'p' && powerUpBars >= 5){//POWER UP
      state.currentTetromino = copyTetro(state.nextTetromino);
      state.nextTetromino = getRandomTetromino();
      powerUpBars = 0;
      if(!isValidState(state)) break;
      showGameState(state,score, powerUpBars);

    }
    else if(counter >= 6){
      counter = 0;
      state = moveDown(state);
      if(isOver(state)){
        state = backup;
        state = appendPiece(state);
        state = simplify(state,score,powerUpBars);
        state.currentTetromino = copyTetro(state.nextTetromino);
        state.nextTetromino = getRandomTetromino();
        if(!isValidState(state)) break;

      }
      showGameState(state,score, powerUpBars);
    }

    while ((action = getch()) != -1);
    usleep(35000);


  }

  ifstream in("records.txt");
  int record;
  in >> record;
  in.close();
  if(score > record) record = score;
  ofstream out("records.txt");
  out << record;
  out.close();
}

void endGame(){
}
