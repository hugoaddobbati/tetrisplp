#include "gui.h"
#pragma once

void drawBackground(){
  attron(COLOR_PAIR(WHITE_PAIR));
  for(int i = 1; i < 21; i++){
    mvhline(i, 1, ' ', 20);
  }
  attroff(COLOR_PAIR(WHITE_PAIR));
}

void startUp(){
  WINDOW * win = initscr();
  cbreak();
  noecho();
  nodelay(win,true);
  setupColors();
  drawBackground();

}

GameState generateIntialState(){
    GameState state;

    return state;
}

void drawPoints(GameState state){
  for(int i = 0; i < state.qtdActivePoints; i++){
    attron(COLOR_PAIR(state.activePoints[i].color));
    mvaddch(state.activePoints[i].y, state.activePoints[i].x, ' ');
    attroff(COLOR_PAIR(state.activePoints[i].color));
  }
}

void showGameState(GameState state){
  drawBackground();
  drawPoints(state);
}

char getChar(){
  char ret = getch();
  return ret;
}

void rollback(){

}
