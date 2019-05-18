#ifndef LORE
#define LORE

#include <stdio.h>

typedef struct{
	int day;
	int month;
	int year;
}tData;

void rndGenInit();
int rnd(int min, int max);
FILE* fileOpen(const char filename[], const char perm[]);
void dataRead(tData out);
void fdataRead(FILE* file, tData out);


#endif
