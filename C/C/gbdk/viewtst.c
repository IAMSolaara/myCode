#include <stdio.h>
#include <gb/gb.h>

#define MDIM 17
#define VDIM 20

int charPos[2];

char mat[MDIM][VDIM];

void matInit(){
	int i, j;
	i=0;
	while (i < MDIM){
		j=0;
		while (j < VDIM){
			mat[i][j]=' ';
			j++;
		}
		i++;
	}
	mat[charPos[0]][charPos[1]]='#';
}



void matView(){
	int i, j;
	i=0;
	while (i < MDIM){
		j=0;
		while (j < VDIM){
			printf("%c", mat[i][j]);
			j++;
		}
		i++;
	}
}

void main(){
	charPos[0]= (MDIM-1)/2; charPos[1]= (VDIM-1)/2;
	matInit();
	while (1) {
		matView();
	}
}

