#include <stdio.h>
#include <gb/gb.h>

extern UBYTE _cpu;

void main(){
  printf("%x", _cpu);
}
