#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <162lib.h>
#include <ncurses.h>

#define HDIM 10
#define VDIM 10

//bidim array functions
void rndGen(const int w, const int h, int out[w][h]);
void chamberInit(const int w, const int h, int out[w][h]);
void GOLCheck(const int w, const int h, int out[w][h], int in[w][h]);
void copyArray(const int w, const int h, int out[w][h], int in[w][h]);
void printArray(const int w, const int h, const int scr[w][h]);
void NCprintArray(const int w, const int h, const int scr[w][h]);
int countNeighbors(const int x, const int y, const int w, const int h, const int in[w][h]);

int main(int argv, char* argc){
  int chamber[HDIM][VDIM];
  int prevChamber[HDIM][VDIM];

  srand(time(NULL));

  initscr();
  noecho();

  chamberInit(HDIM, VDIM, chamber);
  //rndGen(HDIM, VDIM, chamber);

  NCprintArray(HDIM, VDIM, chamber);
  copyArray(HDIM, VDIM, prevChamber, chamber);
  refresh();
  mvprintw(VDIM+20, 0, "Press a key to advance generations.");
  getch();

  

  for (int i = 1; i < 50; i++) {
    mvprintw(VDIM+25, 0, "Generation %d", i);
    GOLCheck(HDIM, VDIM, chamber, prevChamber);
    NCprintArray(HDIM, VDIM, chamber);
    copyArray(HDIM, VDIM, prevChamber, chamber);
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

void chamberInit(const int w, const int h, int out[w][h]){
  for (int i = 0; i < w; i++){
    for (int j = 0; j < h; j++){
      out[i][j] = 0;
      //getch();
    }
  }
  out[3][3] = 1;
  out[3][4] = 1;
  out[3][5] = 1;
  
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
      mvaddch(j, i,  ((scr[i][j]) ? '#' : ' '));
    }
    //printf("\n");
  }
  //printf("chamber\n");
}

/* void GOLCheck(const int w, const int h, int out[w][h], int in[w][h]){ */
/*   int neighbors; */
/*   //chamber loop */
/*   for (int i = 1; i < w-1; i++){ */
/*     for (int j = 1; j < h-1; j++){ */
/*       neighbors = 0; */

/*       //per-cell loop */
/*       for (int x = i - 1; x <= i + 1; x++) { */
/* 	for (int y = j - 1; y <= j + 1; y++) { */
/* 	  if (x == i && y == j) {} */
/* 	  else neighbors += in[y][x]; */
/* 	  //printf("cell %d %d - neighbors %d\n", i, j, neighbors); */
/* 	} */
/*       } */
/*       if (out[i][j]) { //alive cell */
/* 	if (neighbors < 2) out[i][j] = 0; */
/* 	if (neighbors > 3) out[i][j] = 0; */
/*       } */
/*       else {  //dead cell */
/* 	if (neighbors == 3) out[i][j] == 1; */
/*       } */
/*     } */
/*   } */
/* } */

void GOLCheck(const int w, const int h, int out[w][h], int in[w][h]){
  int neighbors;
  int state;
  //chamber loop
  for (int i = 1; i < w-1; i++){
    for (int j = 1; j < h-1; j++){
      neighbors = countNeighbors(i, j, w, h, in);
      mvprintw(h + 29, 0, "Current cell: %d %d", i, j);
      mvprintw(h + 30, 0, "Current neighbors: %d", neighbors);
      state = in[i][j];

      if (state == 1) { //alive cell
        if (neighbors < 2) out[i][j] = 0;
        if (neighbors > 3) out[i][j] = 0;
      }
      else if (state == 0){  //dead cell
        if (neighbors == 3) out[i][j] == 1;
      }
      else out[i][j] = state;
      getch();
    }
  }
}

int countNeighbors(const int x, const int y, const int w, const int h, const int in[w][h]){
  int out = 0;
  int col, row;

  for (int i = -1; i < 2; i++) {
    for (int j = -1; j < 2; j++) {
      col = (x + i + w) % w;
      row = (y + j + h) % h;
      out += in[col][row];
    }
  }
  out -= in[x][y];
  return out;
}
