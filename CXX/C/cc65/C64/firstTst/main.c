#include <stdio.h>
#include <peekpoke.h>
#include <c64.h>
#include <stdlib.h>

void wait(int wt);


int main(){
  int x = 54;
  while (1) {
    scanf("%d", &x);
    printf("%d\n", x);
  }
  return 0;
}

void gae() {
  printf("UR MOM GAE HAHAAHA");
  while (1) {
    POKE(0xD020, rand());
    wait(200);
  }
}


void wait(int wt) {
  int x=0;
  while (x < wt){

    x++;
  }
}
