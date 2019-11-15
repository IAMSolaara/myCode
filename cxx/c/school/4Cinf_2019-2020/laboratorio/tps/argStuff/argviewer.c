#include <stdio.h>

int main(int argv, char** argc) {
	if (argv < 2) printf("Please give at least 1 parameter.\n");
	else {
		printf("%s\n", argc[1]);
	}
}
