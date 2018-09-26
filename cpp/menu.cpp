#include "menu.h"
#include "tetris.h"
#include <unistd.h>
#include <windows.h>
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
    Sleep(150);
  }
  endwin();
}
