#include "menu.h"
#include "tetris.h"
#include <unistd.h>

#pragma once
void generateStartupFrames(){
  startUp();
  char c;
  bool gameActive = 1;
  bool showText = 1;
  while(gameActive){
    c = getch();
    if(c == 's'){
      clearScreen();
      start();
      showMenuOptions(showText);
      usleep(5000);
    }
    else if(c == 'q'){
      gameActive = 0;
    }
    else{
      clearScreen();
      showMenuOptions(showText);
      showText = !showText;
    }
    // Sleep(500);

    while((c = getch()) != -1);
    usleep(500000);
  }
  endwin();
}
