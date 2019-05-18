#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

int rnd(int min, int max);
void rndCol();

int main() {
  printf("%d %d", COLOR_BLACK, COLOR_WHITE);
  srand(time(NULL));
  int st=1;
  int c=0;
  int x, y; x=y=0;
  char ch;
  initscr();      //init ncurses screen
  cbreak();
  start_color();
  noecho();
  double cTst=0;
  init_pair(0, COLOR_BLACK, COLOR_BLACK);
  init_pair(1, COLOR_BLACK, COLOR_RED);
  init_pair(2, COLOR_BLACK, COLOR_YELLOW);
  init_pair(3, COLOR_BLACK, COLOR_GREEN);
  init_pair(4, COLOR_BLACK, COLOR_BLUE);
  init_pair(5, COLOR_BLACK, COLOR_WHITE);
  init_pair(6, COLOR_BLACK, COLOR_CYAN);
  init_pair(7, COLOR_BLACK, COLOR_MAGENTA);
  //black fg, color bg
  init_pair(8, COLOR_GREEN, COLOR_BLACK);
  init_pair(9, COLOR_BLUE, COLOR_BLACK);
  init_pair(10, COLOR_BLACK, COLOR_BLACK);
  init_pair(11, COLOR_BLACK, COLOR_BLACK);
  init_pair(12, COLOR_BLACK, COLOR_BLACK);
  init_pair(13, COLOR_BLACK, COLOR_BLACK);
  init_pair(14, COLOR_BLACK, COLOR_BLACK);
  init_pair(15, COLOR_BLACK, COLOR_BLACK);
  
  while (st) {
    if (cTst) {
      attron(COLOR_PAIR(rnd(0,15)));
      x = rnd(0, COLS - 1);
      y = rnd(0, LINES - 1);
      mvaddch(y, x, '#');
      refresh();
      cTst = 0;
    }
    cTst += 0.00000000001;
  }
  endwin();
  return 0;
}

int rnd(int min, int max) {
  return rand()%(max-min+1)+min;
}

void rndCol() {
  int cTst = rnd(0, 15);
  switch (cTst) {
  case 0 : init_pair(0, COLOR_BLACK, COLOR_BLACK);
  case 1 : init_pair(0, COLOR_BLACK, COLOR_RED);
  }
}
