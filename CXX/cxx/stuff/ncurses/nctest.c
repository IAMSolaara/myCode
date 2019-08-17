#include <ncurses.h>

int rnd(min,max);

int main() {
  int st=1;
  int c=0;
  int x, y; x=y=0;
  initscr();      //init ncurses screen
  start_color();
  noecho();
  init_pair(0, COLOR_RED, COLOR_BLACK);
  init_pair(1, COLOR_GREEN, COLOR_BLACK);
  init_pair(2, COLOR_YELLOW, COLOR_BLACK);
  init_pair(3, COLOR_BLUE, COLOR_BLACK);
  init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(5, COLOR_CYAN, COLOR_BLACK);
  init_pair(6, COLOR_WHITE, COLOR_BLACK);
  while (st && y < LINES) {
    x=0;
    while (st && x < COLS) {
      if (c == 7) c=0;
      attron(COLOR_PAIR(c));
      mvaddch(y, x, '#');

      refresh();
      x += 1;
      c++;
    }
    y += 1;
  }
  getch();
  endwin();
  return 0;
}

int rnd(min, max) {
  
