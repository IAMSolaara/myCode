#include <stdio.h>
#include <gb/gb.h>

void endl(){puts("\n");}

typedef struct{
	int field1;
	char field2[];
	float field3;
}rectst;

void main(){
	rectst.field1 = 56;
	rectst.field3 = 78.46;
	puts(rectst.field2);
	printf("%d", rectst.field1);
	printf("%f", rectst.field3);
}
