#include "gui.h"
#include <string>
#include <sstream>
#include <unistd.h>
#pragma once

WINDOW * win;




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

void clearScreen(){
  attron(COLOR_PAIR(EMPTY));
  for(int i = 0; i < LINES; i++){
    for(int j = 0; j < COLS; j++){
      mvaddch(i, j, ' ');
    }
  }
  attroff(COLOR_PAIR(EMPTY));
}

void disableDelay(){
  nodelay(win, true);
}
void enableDelay(){
  nodelay(win, false);
}

void showMenuOptions(){
  clearScreen();
  for(int line = 1; line < 9; line++){
    mvprintw(line, 1, menuText[line-1]);
  }
  refresh();
}

void startUp(){
  win = initscr();
  cbreak();
  keypad(stdscr, TRUE);
  noecho();
  disableDelay();
  setupColors();
  srand(time(NULL));

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


void drawExtraInfo(GameState state, int score, int powerUpBar){
  int xOFFSET = 40;
  int yOFFSET = 30;
  std::string s = std::to_string(score);
  char const *scoree = s.c_str();
  char scoreMsg[] = "SCORE";
  char nextmsg[] = "NEXT TETROMINO";
  char powerUp[] = "POWERUPBAR";
  mvprintw(yOFFSET-15, 16+xOFFSET, scoree);
  mvprintw(yOFFSET-17 , 16+xOFFSET, scoreMsg);
  mvprintw(yOFFSET-10, 16+xOFFSET, powerUp);
  attron(COLOR_PAIR(BLUE_PAIR));
  for(int i = 0; i < powerUpBar; i++){
    mvaddch(yOFFSET-9, 16+xOFFSET+i*2, ' ');
    mvaddch(yOFFSET-9, 16+xOFFSET+i*2+1, ' ');
  }
  attroff(COLOR_PAIR(BLUE_PAIR));
  attron(COLOR_PAIR(YELLOW_PAIR));
  for(int i = powerUpBar; i <= 4 ; i++){
    mvaddch(yOFFSET-9, 16+xOFFSET+i*2, ' ');
    mvaddch(yOFFSET-9, 16+xOFFSET+i*2+1, ' ');
  }
  attroff(COLOR_PAIR(YELLOW_PAIR));
  mvprintw(yOFFSET-1, 15+xOFFSET, nextmsg);
  for(int i = 0; i < 4; i++){
    attron(COLOR_PAIR(EMPTY));
    mvaddch(2*state.currentTetromino.points[i].y+1+yOFFSET, 4*state.currentTetromino.points[i].x+1+xOFFSET, ' ');
    mvaddch(2*state.currentTetromino.points[i].y+1+yOFFSET, 4*state.currentTetromino.points[i].x+2+xOFFSET, ' ');
    mvaddch(2*state.currentTetromino.points[i].y+2+yOFFSET, 4*state.currentTetromino.points[i].x+1+xOFFSET, ' ');
    mvaddch(2*state.currentTetromino.points[i].y+2+yOFFSET, 4*state.currentTetromino.points[i].x+2+xOFFSET, ' ');
    mvaddch(2*state.currentTetromino.points[i].y+1+yOFFSET, 4*state.currentTetromino.points[i].x+3+xOFFSET, ' ');
    mvaddch(2*state.currentTetromino.points[i].y+1+yOFFSET, 4*state.currentTetromino.points[i].x+4+xOFFSET, ' ');
    mvaddch(2*state.currentTetromino.points[i].y+2+yOFFSET, 4*state.currentTetromino.points[i].x+3+xOFFSET, ' ');
    mvaddch(2*state.currentTetromino.points[i].y+2+yOFFSET, 4*state.currentTetromino.points[i].x+4+xOFFSET, ' ');
    attroff(COLOR_PAIR(EMPTY));
  }
  for(int i = 0; i < 4; i++){
    attron(COLOR_PAIR(state.nextTetromino.points[i].color));
    mvaddch(2*state.nextTetromino.points[i].y+1+yOFFSET, 4*state.nextTetromino.points[i].x+1+xOFFSET, ' ');
    mvaddch(2*state.nextTetromino.points[i].y+1+yOFFSET, 4*state.nextTetromino.points[i].x+2+xOFFSET, ' ');
    mvaddch(2*state.nextTetromino.points[i].y+2+yOFFSET, 4*state.nextTetromino.points[i].x+1+xOFFSET, ' ');
    mvaddch(2*state.nextTetromino.points[i].y+2+yOFFSET, 4*state.nextTetromino.points[i].x+2+xOFFSET, ' ');
    mvaddch(2*state.nextTetromino.points[i].y+1+yOFFSET, 4*state.nextTetromino.points[i].x+3+xOFFSET, ' ');
    mvaddch(2*state.nextTetromino.points[i].y+1+yOFFSET, 4*state.nextTetromino.points[i].x+4+xOFFSET, ' ');
    mvaddch(2*state.nextTetromino.points[i].y+2+yOFFSET, 4*state.nextTetromino.points[i].x+3+xOFFSET, ' ');
    mvaddch(2*state.nextTetromino.points[i].y+2+yOFFSET, 4*state.nextTetromino.points[i].x+4+xOFFSET, ' ');
    attroff(COLOR_PAIR(state.nextTetromino.points[i].color));
  }

}

void showGameState(GameState state, int score, int powerUpBar){
  drawBackground();
  drawPoints(state);
  drawExtraInfo(state, score, powerUpBar);
  mvgetch(100,100);
  refresh();
}

char getChar(){
  char ret = getch();
  return ret;
}

void rollback(){

}
