#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(int argc, char* argv[]) {
  int out;
  if (argc < 4) printf("Please give at least 3 parameters.\n");
  else {
   
    if (!strcmp(argv[2], "+"))    out = atoi(argv[1]) + atoi(argv[3]);
    if (!strcmp(argv[2], "-"))    out = atoi(argv[1]) - atoi(argv[3]);
    if (!strcmp(argv[2], "*"))    out = atoi(argv[1]) * atoi(argv[3]);
    if (!strcmp(argv[2], "/")) {
      if (strcmp(argv[3], "0")) out = atoi(argv[1]) / atoi(argv[3]);
      else out = -1;
    }
  

    if (out != -1) printf("The result of the operation you gave me is %d.\n", out);
    else printf("You gave me an invalid parameter :(");
  }
}
