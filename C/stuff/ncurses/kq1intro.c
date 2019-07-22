#include <ncurses.h>
#include <stdlib.h>

WINDOW *create_newwin(int height, int width, int starty, int startx);

int main() {
  WINDOW* bg;
  initscr();
  start_color();
  noecho();
  init_pair(0, COLOR_BLUE, COLOR_BLUE);
  wbkgd(stdscr, COLOR_PAIR(0));
  box(stdscr, 'ACS_CKBOARD', 'ACS_CKBOARD');
  
  
  
  getch();
  endwin();
  return 0;
}


WINDOW *create_newwin(int height, int width, int starty, int startx) {
  WINDOW *local_win;
  
  local_win = newwin(height, width, starty, startx);
  box(local_win, '#' , '#');	/* 0, 0 gives default characters 
				 * for the vertical and horizontal
				 * lines			*/
  wrefresh(local_win);		/* Show that box 		*/
  
  return local_win;
}
