#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <162lib.h>

#define REFRBASE 500000000
#define REFRESH REFRBASE / 120


void main() {
  int clk=0;
  char mz[] = {'\\', '/'};
  srand(time(NULL));
  while (1){
    if (clk > REFRESH) {
      printf("%c", mz[rnd(0,1)]);
      clk=0;
    }
    clk++;
  }
}
