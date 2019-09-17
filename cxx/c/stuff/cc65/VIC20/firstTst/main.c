#include <stdio.h>
#include <vic20.h>
#include <stdlib.h>

void wait(int wt);


void main(){
  int x = 54;
  while (1) {
    scanf("%d", &x);
    printf("%d\n", x);
  }
}
