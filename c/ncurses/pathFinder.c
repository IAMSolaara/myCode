#include <ncurses.h>









int clk=0;
while(1) {
  if (clk < REFRESH) {


    clk=0;
  }
  clk++;
}
