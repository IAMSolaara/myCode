#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <162lib.h>
#include <ncurses.h>

#define HDIM 11
#define VDIM 10

//bidim array functions
void rndGen(const int w, const int h, int out[w][h]);
void GOLCheck(const int w, const int h, int out[w][h], int in[w][h]);
void copyArray(const int w, const int h, int out[w][h], int in[w][h]);
void printArray(const int w, const int h, const int scr[w][h]);
void NCprintArray(const int w, const int h, const int scr[w][h]);

int main(int argv, char* argc){
  int chamber[HDIM][VDIM];
  int prevChamber[HDIM][VDIM];

  srand(time(NULL));

  initscr();
  noecho();
  
  rndGen(HDIM, VDIM, chamber);

  printArray(HDIM, VDIM, chamber);

  copyArray(HDIM, VDIM, prevChamber, chamber);

  for (int i = 0; i < 50; i++) {
    GOLCheck(HDIM, VDIM, chamber, prevChamber);
    NCprintArray(HDIM, VDIM, chamber);
    refresh();
    getch();
  }

  
  /*
  //dump chamber contents
  for (int i = 0; i < HDIM; i++) {
    printArray(chamber[i], VDIM);
  }
  */
  endwin();
  return 0;
}


void rndGen(const int w, const int h, int out[w][h]){
  for (int i = 0; i < w; i++){
    for (int j = 0; j < h; j++){
      out[i][j] = rnd(0,1);
    }
  }
}



void copyArray(const int w, const int h, int out[w][h], int in[w][h]){
  for (int i = 0; i < w; i++){
    for (int j = 0; j < h; j++){
      out[i][j] = in[i][j];
    }
  }
}

void printArray(const int w, const int h, const int scr[w][h]){
  for (int i = 0; i < w; i++){
    for (int j = 0; j < h; j++){
      printf(" %c ", (scr[i][j]) ? '#' : ' ');
    }
    printf("\n");
  }
  printf("chamber\n");
}

void NCprintArray(const int w, const int h, const int scr[w][h]){
  for (int i = 0; i < w; i++){
    for (int j = 0; j < h; j++){
      mvaddch( ((scr[i][j]) ? '#' : ' '), i, j );
    }
    //printf("\n");
  }
  //printf("chamber\n");
}

void GOLCheck(const int w, const int h, int out[w][h], int in[w][h]){
  int neighbors;
  //chamber loop
  for (int i = 1; i < w-1; i++){
    for (int j = 1; j < h-1; j++){
      neighbors = 0;
      
      //per-cell loop
      for (int x = i - 1; x <= i + 1; x++) {
	for (int y = j - 1; y <= j + 1; y++) {
	  if (x == i && y == j) {}
	  else neighbors += in[y][x];
	}
      }
      if (out[i][j]) { //alive cell
	if (neighbors < 2) out[i][j] = 0;
	if (neighbors > 3) out[i][j] = 0;
      }
      else {  //dead cell
	if (neighbors == 3) out[i][j] == 1;
      }
    }
  }
  copyArray(HDIM, VDIM, in, out);
}
