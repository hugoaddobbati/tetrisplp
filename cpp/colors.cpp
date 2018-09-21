#include "colors.h"
void setupColors(){
  start_color();
  init_pair(EMPTY, COLOR_BLACK, COLOR_BLACK);
  init_pair(RED_PAIR, COLOR_RED, COLOR_RED);
  init_pair(BLUE_PAIR, COLOR_BLUE, COLOR_BLUE);
  init_pair(GREEN_PAIR, COLOR_GREEN, COLOR_GREEN);
  init_pair(YELLOW_PAIR, COLOR_YELLOW, COLOR_YELLOW);
  init_pair(MAGENTA_PAIR, COLOR_MAGENTA, COLOR_MAGENTA);
  init_pair(CYAN_PAIR, COLOR_CYAN, COLOR_CYAN);
  init_pair(WHITE_PAIR, COLOR_WHITE, COLOR_WHITE);
}
