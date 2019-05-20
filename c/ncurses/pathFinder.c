#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

int rnd(int min, int max);

int main(){
  int x, y;
  int runs;
  int dir;
  char ch='#';
  struct timespec wtime;
  wtime.tv_sec = 0; wtime.tv_nsec=100000000;
  printf("How many turns?\n"); scanf("%d%*c", &runs);
  initscr();
  cbreak();
  start_color();
  noecho();
  srand(time(NULL));
  int start[]={rnd(0, COLS), rnd(0, LINES)};
  for (int i; i < runs; i++){
    dir=rnd(0, 7);
    switch(dir){
      case(0): start[0] += 1; break;
      case(1): start[0] -= 1; break;
      case(2): start[1] += 1; break;
      case(3): start[1] -= 1; break;
      case(4): start[0] += 1; start[1] += 1; break;
      case(5): start[0] -= 1; start[1] += 1; break;
      case(6): start[1] += 1; start[0] -= 1; break;
      case(7): start[1] -= 1; start[0] -= 1; break;
    }
    if (start[1] < 0 || start[1] > LINES) start[1] = rnd(0, LINES);
    else if (start[0] < 0 || start[0] > COLS) start[0] = rnd(0, COLS);
    
    mvaddch(start[1], start[0], ch);
    refresh();
    nanosleep(&wtime, NULL);
  }
  getch();
  endwin();
}

int rnd(int min, int max) {
  return rand()%(max-min+1)+min;
}
