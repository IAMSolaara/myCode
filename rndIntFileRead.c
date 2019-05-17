#include <stdio.h>
#include <stdlib.h>

FILE* fileOpen(const char fname[], const char perm[]);
void view(FILE* f);

int main(){
	FILE* f;
	f=fileOpen("out.dat", "r");
	view(f);
	fclose(f);
	return 0;
}

FILE* fileOpen(const char fname[], const char perm[]){
	FILE* out;
	out = fopen(fname, perm);
	if (out == NULL) {
		printf("Errore apertura file.\n");
		exit(-1);
	}
	return out;
}

void view(FILE* f){
	int tmp;
	while(fread(&tmp, sizeof(int), 1, f)){
		printf("%d ", tmp);
	}
	printf("\n");
}
