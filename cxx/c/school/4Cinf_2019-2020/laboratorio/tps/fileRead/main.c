#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argv, char** argc){
	if (argv < 2 || argv > 2) printf("Please supply no more than one parameter.");
	else {
		char* seps;
		FILE* f = fopen(argc[1], "r");
		char c[1000];
		int lns = 0;
		while (fgets(c, 1000, f) != NULL) {

			//printf("%s", c);

			seps = strstr(c, "/");

			printf("%s", seps);
			
			//printName(c, 1000, seps);

			lns++;
		}	

		fclose(f);
		printf("%d lines", lns);
	}
	return 0;
}
