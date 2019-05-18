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
  init_pair(10, COLOR_RED, COLOR_BLACK);
  init_pair(11, COLOR_RED, COLOR_RED);
  init_pair(12, COLOR_RED, COLOR_YELLOW);
  init_pair(13, COLOR_RED, COLOR_GREEN);
  init_pair(14, COLOR_RED, COLOR_BLUE);
  init_pair(15, COLOR_RED, COLOR_WHITE);
  init_pair(16, COLOR_RED, COLOR_CYAN);
  init_pair(17, COLOR_RED, COLOR_MAGENTA);
  //
  init_pair(20, COLOR_YELLOW, COLOR_BLACK);
  init_pair(21, COLOR_YELLOW, COLOR_RED);
  init_pair(22, COLOR_YELLOW, COLOR_YELLOW);
  init_pair(23, COLOR_YELLOW, COLOR_GREEN);
  init_pair(24, COLOR_YELLOW, COLOR_BLUE);
  init_pair(25, COLOR_YELLOW, COLOR_WHITE);
  init_pair(26, COLOR_YELLOW, COLOR_CYAN);
  init_pair(27, COLOR_YELLOW, COLOR_MAGENTA);
  //
  init_pair(30, COLOR_GREEN, COLOR_BLACK);
  init_pair(31, COLOR_GREEN, COLOR_RED);
  init_pair(32, COLOR_GREEN, COLOR_YELLOW);
  init_pair(33, COLOR_GREEN, COLOR_GREEN);
  init_pair(34, COLOR_GREEN, COLOR_BLUE);
  init_pair(35, COLOR_GREEN, COLOR_WHITE);
  init_pair(36, COLOR_GREEN, COLOR_CYAN);
  init_pair(37, COLOR_GREEN, COLOR_MAGENTA);
  //
  init_pair(40, COLOR_RED, COLOR_BLACK);
  init_pair(41, COLOR_RED, COLOR_RED);
  init_pair(42, COLOR_RED, COLOR_YELLOW);
  init_pair(43, COLOR_RED, COLOR_GREEN);
  init_pair(44, COLOR_RED, COLOR_BLUE);
  init_pair(45, COLOR_RED, COLOR_WHITE);
  init_pair(46, COLOR_RED, COLOR_CYAN);
  init_pair(47, COLOR_RED, COLOR_MAGENTA);
  //
  init_pair(50, COLOR_RED, COLOR_BLACK);
  init_pair(51, COLOR_RED, COLOR_RED);
  init_pair(52, COLOR_RED, COLOR_YELLOW);
  init_pair(53, COLOR_RED, COLOR_GREEN);
  init_pair(54, COLOR_RED, COLOR_BLUE);
  init_pair(55, COLOR_RED, COLOR_WHITE);
  init_pair(56, COLOR_RED, COLOR_CYAN);
  init_pair(57, COLOR_RED, COLOR_MAGENTA);
  //
  init_pair(60, COLOR_RED, COLOR_BLACK);
  init_pair(61, COLOR_RED, COLOR_RED);
  init_pair(62, COLOR_RED, COLOR_YELLOW);
  init_pair(63, COLOR_RED, COLOR_GREEN);
  init_pair(64, COLOR_RED, COLOR_BLUE);
  init_pair(65, COLOR_RED, COLOR_WHITE);
  init_pair(66, COLOR_RED, COLOR_CYAN);
  init_pair(67, COLOR_RED, COLOR_MAGENTA);
  //
  init_pair(70, COLOR_RED, COLOR_BLACK);
  init_pair(71, COLOR_RED, COLOR_RED);
  init_pair(72, COLOR_RED, COLOR_YELLOW);
  init_pair(73, COLOR_RED, COLOR_GREEN);
  init_pair(74, COLOR_RED, COLOR_BLUE);
  init_pair(75, COLOR_RED, COLOR_WHITE);
  init_pair(76, COLOR_RED, COLOR_CYAN);
  init_pair(77, COLOR_RED, COLOR_MAGENTA);
  //
  
  while (st) {
    if (cTst) {
      attron(COLOR_PAIR(rnd(0,47)));
      x = rnd(0, COLS - 1);
      y = rnd(0, LINES - 1);
      mvaddch(y, x, rnd('A', 'Z'));
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
  case 0 : init_pair(0, COLOR_RED, COLOR_BLACK);
  case 1 : init_pair(0, COLOR_RED, COLOR_RED);
  }
}
