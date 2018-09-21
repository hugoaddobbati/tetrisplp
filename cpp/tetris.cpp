#include "tetris.h"
#pragma once

void start(){
    startUp();
    play();
}

void play(){
  GameState state = initialize(10,20);
  bool playing = true;
  while(playing){
    char action = getChar();
    switch(action){

    }
  }
}

void endGame(){
  endwin();
}
