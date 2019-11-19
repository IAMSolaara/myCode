#include <stdio.h>
int main(int argv, char** argc){
	if (argv < 2 || argv > 2) printf("Please supply no more than one parameter.");
	else {
		FILE* f = fopen(argc[1], "r");
		char c;
		int lns = 0;
		while (fscanf(f, "%c", &c) != EOF) {
			printf("%c", c);
			if (c == '\n') lns++;
		}
		fclose(f);
		printf("%d lines", lns);
	}
}
