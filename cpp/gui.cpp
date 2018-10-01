#include "gui.h"
#include <string>
#include <sstream>
#include <unistd.h>
#include <sys/ioctl.h>
#include <fstream>

WINDOW * win;

int X_ALIGN, Y_ALIGN_MENU, Y_ALIGN_TETRIS;




void drawBackground(){
  attron(COLOR_PAIR(EMPTY));
  mvhline(0 + X_ALIGN,0 + Y_ALIGN_TETRIS,'@',42);
  for(int i = 1; i < 41; i++){
    mvhline(i + X_ALIGN, 0 + Y_ALIGN_TETRIS, '@', 1);
    mvhline(i + X_ALIGN, 1 + Y_ALIGN_TETRIS, ' ', 40);
    mvhline(i + X_ALIGN, 41 + Y_ALIGN_TETRIS, '@', 1);
  }
  mvhline(41 + X_ALIGN,0 + Y_ALIGN_TETRIS,'@',42);
  attroff(COLOR_PAIR(EMPTY));
}

void clearScreen(){
  attron(COLOR_PAIR(EMPTY));
  for(int i = 0; i < LINES; i++){
    for(int j = 0; j < COLS; j++){
      mvaddch(i + X_ALIGN, j + Y_ALIGN_MENU, ' ');
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

void showMenuOptions(bool showText){
  clearScreen();
  for(int line = 1; line < 23; line++){
    mvprintw(line + X_ALIGN, 1 + Y_ALIGN_MENU, menuText[line-1]);
  }
  if(showText){
    for(int i = 23; i < 29; i++){
      mvprintw(i +1 + X_ALIGN,1 + Y_ALIGN_MENU, startText[i-23]);
    }
  }
  mvprintw(500 + X_ALIGN,500 + Y_ALIGN_MENU," ");
  refresh();
}

void startUp(){
  win = initscr();
  struct winsize ts;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &ts);
  X_ALIGN = (ts.ws_row - 42) / 2;
  Y_ALIGN_MENU = (ts.ws_col - 150) / 2;
  Y_ALIGN_TETRIS = (ts.ws_col - 66) / 2;
  cbreak();
  keypad(stdscr, TRUE);
  curs_set(0);
  noecho();
  disableDelay();
  setupColors();
}

GameState generateIntialState(){
    GameState state;

    return state;
}

void drawPoints(GameState state){
  for(int i = 0; i < state.qtdActivePoints; i++){
    attron(COLOR_PAIR(state.activePoints[i].color));
    mvaddch(2*state.activePoints[i].y+1 + X_ALIGN, 4*state.activePoints[i].x+1 + Y_ALIGN_TETRIS, ' ');
    mvaddch(2*state.activePoints[i].y+1 + X_ALIGN, 4*state.activePoints[i].x+2 + Y_ALIGN_TETRIS, ' ');
    mvaddch(2*state.activePoints[i].y+2 + X_ALIGN, 4*state.activePoints[i].x+1 + Y_ALIGN_TETRIS, ' ');
    mvaddch(2*state.activePoints[i].y+2 + X_ALIGN, 4*state.activePoints[i].x+2 + Y_ALIGN_TETRIS, ' ');
    mvaddch(2*state.activePoints[i].y+1 + X_ALIGN, 4*state.activePoints[i].x+3 + Y_ALIGN_TETRIS, ' ');
    mvaddch(2*state.activePoints[i].y+1 + X_ALIGN, 4*state.activePoints[i].x+4 + Y_ALIGN_TETRIS, ' ');
    mvaddch(2*state.activePoints[i].y+2 + X_ALIGN, 4*state.activePoints[i].x+3 + Y_ALIGN_TETRIS, ' ');
    mvaddch(2*state.activePoints[i].y+2 + X_ALIGN, 4*state.activePoints[i].x+4 + Y_ALIGN_TETRIS, ' ');
    attroff(COLOR_PAIR(state.activePoints[i].color));
  }
  for(int i = 0; i < 4; i++){
    attron(COLOR_PAIR(state.currentTetromino.points[i].color));
    mvaddch(2*state.currentTetromino.points[i].y+1 + X_ALIGN, 4*state.currentTetromino.points[i].x+1 + Y_ALIGN_TETRIS, ' ');
    mvaddch(2*state.currentTetromino.points[i].y+1 + X_ALIGN, 4*state.currentTetromino.points[i].x+2 + Y_ALIGN_TETRIS, ' ');
    mvaddch(2*state.currentTetromino.points[i].y+2 + X_ALIGN, 4*state.currentTetromino.points[i].x+1 + Y_ALIGN_TETRIS, ' ');
    mvaddch(2*state.currentTetromino.points[i].y+2 + X_ALIGN, 4*state.currentTetromino.points[i].x+2 + Y_ALIGN_TETRIS, ' ');
    mvaddch(2*state.currentTetromino.points[i].y+1 + X_ALIGN, 4*state.currentTetromino.points[i].x+3 + Y_ALIGN_TETRIS, ' ');
    mvaddch(2*state.currentTetromino.points[i].y+1 + X_ALIGN, 4*state.currentTetromino.points[i].x+4 + Y_ALIGN_TETRIS, ' ');
    mvaddch(2*state.currentTetromino.points[i].y+2 + X_ALIGN, 4*state.currentTetromino.points[i].x+3 + Y_ALIGN_TETRIS, ' ');
    mvaddch(2*state.currentTetromino.points[i].y+2 + X_ALIGN, 4*state.currentTetromino.points[i].x+4 + Y_ALIGN_TETRIS, ' ');
    attroff(COLOR_PAIR(state.currentTetromino.points[i].color));
  }
}

std::string getRecord(){
  std::string record;
  std::ifstream in("records.txt");
  in >> record;
  in.close();
  return record;
}

void drawExtraInfo(GameState state, int score, int powerUpBar){
  int xOFFSET = 40;
  int yOFFSET = 30;
  std::string s = std::to_string(score);
  char const *scoree = s.c_str();
  char const *recordv = getRecord().c_str();
  char recordMsg[] = "RECORD";
  char scoreMsg[] = "SCORE";
  char nextmsg[] = "NEXT TETROMINO";
  char powerUp[] = "POWERUPBAR";

  /**
  * RECORD
  * */ 
  mvprintw(yOFFSET-22 + X_ALIGN, 16+xOFFSET + Y_ALIGN_TETRIS, recordv);
  mvprintw(yOFFSET-24 + X_ALIGN, 16+xOFFSET + Y_ALIGN_TETRIS, recordMsg);


  /**
   * Score
   * */
  mvprintw(yOFFSET-15 + X_ALIGN, 16+xOFFSET + Y_ALIGN_TETRIS, scoree);
  mvprintw(yOFFSET-17 + X_ALIGN, 16+xOFFSET + Y_ALIGN_TETRIS, scoreMsg);

  mvprintw(yOFFSET-10 + X_ALIGN, 16+xOFFSET + Y_ALIGN_TETRIS, powerUp);
  attron(COLOR_PAIR(BLUE_PAIR));
  for(int i = 0; i < powerUpBar; i++){
    mvaddch(yOFFSET-9 + X_ALIGN, 16+xOFFSET+i*2 + Y_ALIGN_TETRIS, ' ');
    mvaddch(yOFFSET-9 + X_ALIGN, 16+xOFFSET+i*2+1 + Y_ALIGN_TETRIS, ' ');
  }
  attroff(COLOR_PAIR(BLUE_PAIR));
  attron(COLOR_PAIR(YELLOW_PAIR));
  for(int i = powerUpBar; i <= 4 ; i++){
    mvaddch(yOFFSET-9 + X_ALIGN, 16+xOFFSET+i*2 + Y_ALIGN_TETRIS, ' ');
    mvaddch(yOFFSET-9 + X_ALIGN, 16+xOFFSET+i*2+1 + Y_ALIGN_TETRIS, ' ');
  }
  attroff(COLOR_PAIR(YELLOW_PAIR));
  mvprintw(yOFFSET-1 + X_ALIGN, 15+xOFFSET + Y_ALIGN_TETRIS, nextmsg);
  for(int i = 0; i < 4; i++){
    attron(COLOR_PAIR(EMPTY));
    mvaddch(2*state.currentTetromino.points[i].y+1+yOFFSET + X_ALIGN, 4*state.currentTetromino.points[i].x+1+xOFFSET + Y_ALIGN_TETRIS, ' ');
    mvaddch(2*state.currentTetromino.points[i].y+1+yOFFSET + X_ALIGN, 4*state.currentTetromino.points[i].x+2+xOFFSET + Y_ALIGN_TETRIS, ' ');
    mvaddch(2*state.currentTetromino.points[i].y+2+yOFFSET + X_ALIGN, 4*state.currentTetromino.points[i].x+1+xOFFSET + Y_ALIGN_TETRIS, ' ');
    mvaddch(2*state.currentTetromino.points[i].y+2+yOFFSET + X_ALIGN, 4*state.currentTetromino.points[i].x+2+xOFFSET + Y_ALIGN_TETRIS, ' ');
    mvaddch(2*state.currentTetromino.points[i].y+1+yOFFSET + X_ALIGN, 4*state.currentTetromino.points[i].x+3+xOFFSET + Y_ALIGN_TETRIS, ' ');
    mvaddch(2*state.currentTetromino.points[i].y+1+yOFFSET + X_ALIGN, 4*state.currentTetromino.points[i].x+4+xOFFSET + Y_ALIGN_TETRIS, ' ');
    mvaddch(2*state.currentTetromino.points[i].y+2+yOFFSET + X_ALIGN, 4*state.currentTetromino.points[i].x+3+xOFFSET + Y_ALIGN_TETRIS, ' ');
    mvaddch(2*state.currentTetromino.points[i].y+2+yOFFSET + X_ALIGN, 4*state.currentTetromino.points[i].x+4+xOFFSET + Y_ALIGN_TETRIS, ' ');
    attroff(COLOR_PAIR(EMPTY));
  }
  for(int i = 0; i < 4; i++){
    attron(COLOR_PAIR(state.nextTetromino.points[i].color));
    mvaddch(2*state.nextTetromino.points[i].y+1+yOFFSET + X_ALIGN, 4*state.nextTetromino.points[i].x+1+xOFFSET + Y_ALIGN_TETRIS, ' ');
    mvaddch(2*state.nextTetromino.points[i].y+1+yOFFSET + X_ALIGN, 4*state.nextTetromino.points[i].x+2+xOFFSET + Y_ALIGN_TETRIS, ' ');
    mvaddch(2*state.nextTetromino.points[i].y+2+yOFFSET + X_ALIGN, 4*state.nextTetromino.points[i].x+1+xOFFSET + Y_ALIGN_TETRIS, ' ');
    mvaddch(2*state.nextTetromino.points[i].y+2+yOFFSET + X_ALIGN, 4*state.nextTetromino.points[i].x+2+xOFFSET + Y_ALIGN_TETRIS, ' ');
    mvaddch(2*state.nextTetromino.points[i].y+1+yOFFSET + X_ALIGN, 4*state.nextTetromino.points[i].x+3+xOFFSET + Y_ALIGN_TETRIS, ' ');
    mvaddch(2*state.nextTetromino.points[i].y+1+yOFFSET + X_ALIGN, 4*state.nextTetromino.points[i].x+4+xOFFSET + Y_ALIGN_TETRIS, ' ');
    mvaddch(2*state.nextTetromino.points[i].y+2+yOFFSET + X_ALIGN, 4*state.nextTetromino.points[i].x+3+xOFFSET + Y_ALIGN_TETRIS, ' ');
    mvaddch(2*state.nextTetromino.points[i].y+2+yOFFSET + X_ALIGN, 4*state.nextTetromino.points[i].x+4+xOFFSET + Y_ALIGN_TETRIS, ' ');
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
