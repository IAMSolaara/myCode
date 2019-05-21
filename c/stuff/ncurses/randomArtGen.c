#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

int rnd(int min, int max);

int main(){
  char pal[]={';', '%', 'F', '['};
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
  int x = rnd(0, COLS), y = rnd(0, LINES);
  for (int i; i < runs; i++){
    dir=rnd(0, 7);
    switch(dir){
      case(0): x += 1; break;
      case(1): x -= 1; break;
      case(2): y += 1; break;
      case(3): y -= 1; break;
      case(4): x += 1; y += 1; break;
      case(5): x -= 1; y += 1; break;
      case(6): y -= 1; x += 1; break;
      case(7): y -= 1; x -= 1; break;
    }
    if (y < 0 || y > LINES) y = rnd(0, LINES);
    else if (x < 0 || x > COLS) x = rnd(0, COLS);

    if (mvinch(y,x) == pal[0]) ch = pal[1];
    else if (mvinch(y,x) == pal[1]) ch = pal[2];
    else if (mvinch(y,x) == pal[2]) ch = pal[3];
    else if (mvinch(y,x) == pal[3]) ch = pal[3];
    mvaddch(y, x, ch);
    ch = pal[0];
    refresh();
    nanosleep(&wtime, NULL);
  }
  getch();
  endwin();
}

int rnd(int min, int max) {
  return rand()%(max-min+1)+min;
}
