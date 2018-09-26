#include "menu.h"
#include "tetris.h"
#include <unistd.h>
#pragma once
void generateStartupFrames(){
  startUp();
  char c;
  bool gameActive = 1;
  while(gameActive){
    c = getch();
    if(c == 's'){
      start();
    }
    else if(c == 'q'){
      gameActive = 0;
    }
    else{
      clearScreen();
      showMenuOptions();
    }
    usleep(150000);
  }
  endwin();
}
