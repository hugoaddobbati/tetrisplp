#include "gui.h"
#pragma once

void drawBackground(){
  attron(COLOR_PAIR(EMPTY));
  mvhline(0,0,'@',42);
  for(int i = 1; i < 41; i++){
    mvhline(i, 0, '@', 1);
    mvhline(i, 1, ' ', 40);
    mvhline(i, 41, '@', 1);
  }
  mvhline(41,0,'@',42);
  attroff(COLOR_PAIR(EMPTY));
}

void showScore(int score){

}

void startUp(){
  WINDOW * win = initscr();
  cbreak();
  keypad(stdscr, TRUE);
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
    mvaddch(2*state.activePoints[i].y+1, 4*state.activePoints[i].x+1, ' ');
    mvaddch(2*state.activePoints[i].y+1, 4*state.activePoints[i].x+2, ' ');
    mvaddch(2*state.activePoints[i].y+2, 4*state.activePoints[i].x+1, ' ');
    mvaddch(2*state.activePoints[i].y+2, 4*state.activePoints[i].x+2, ' ');
    mvaddch(2*state.activePoints[i].y+1, 4*state.activePoints[i].x+3, ' ');
    mvaddch(2*state.activePoints[i].y+1, 4*state.activePoints[i].x+4, ' ');
    mvaddch(2*state.activePoints[i].y+2, 4*state.activePoints[i].x+3, ' ');
    mvaddch(2*state.activePoints[i].y+2, 4*state.activePoints[i].x+4, ' ');
    attroff(COLOR_PAIR(state.activePoints[i].color));
  }
  for(int i = 0; i < 4; i++){
    attron(COLOR_PAIR(state.currentTetromino.points[i].color));
    mvaddch(2*state.currentTetromino.points[i].y+1, 4*state.currentTetromino.points[i].x+1, ' ');
    mvaddch(2*state.currentTetromino.points[i].y+1, 4*state.currentTetromino.points[i].x+2, ' ');
    mvaddch(2*state.currentTetromino.points[i].y+2, 4*state.currentTetromino.points[i].x+1, ' ');
    mvaddch(2*state.currentTetromino.points[i].y+2, 4*state.currentTetromino.points[i].x+2, ' ');
    mvaddch(2*state.currentTetromino.points[i].y+1, 4*state.currentTetromino.points[i].x+3, ' ');
    mvaddch(2*state.currentTetromino.points[i].y+1, 4*state.currentTetromino.points[i].x+4, ' ');
    mvaddch(2*state.currentTetromino.points[i].y+2, 4*state.currentTetromino.points[i].x+3, ' ');
    mvaddch(2*state.currentTetromino.points[i].y+2, 4*state.currentTetromino.points[i].x+4, ' ');
    attroff(COLOR_PAIR(state.currentTetromino.points[i].color));
  }
}

void showGameState(GameState state){
  drawBackground();
  drawPoints(state);
  mvgetch(100,100);
  refresh();
}

char getChar(){
  char ret = getch();
  return ret;
}

void rollback(){

}
