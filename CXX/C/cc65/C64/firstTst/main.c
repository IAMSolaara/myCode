#include <stdio.h>
#include <peekpoke.h>
#include <c64.h>
#include <stdlib.h>

void wait(int wt);

int main() {
  printf("UR MOM GAE HAHAAHA");
  while (1) {
    POKE(0xD020, rand());
    wait(200);
  }
  return 0;
}


void wait(int wt) {
  int x=0;
  while (x < wt){

    x++;
  }
}
