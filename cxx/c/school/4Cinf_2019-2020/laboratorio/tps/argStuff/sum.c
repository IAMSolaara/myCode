#include <stdio.h>

void main(int argc, char* argv[]) {
  if (argc < 3) printf("Please give at least 2 parameters.\n");
  else printf("The sum of the parameters you gave me is %d.\n", (atoi(argv[1]) + atoi(argv[2])));
}
