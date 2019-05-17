#include <stdio.h>

#define MAX 10

void inizializza(int m[][MAX], int max);
void visualizza(int m[][MAX], int max);

int main(){

  int mat[MAX][MAX];

  inizializza(mat,MAX);
  visualizza(mat,MAX);
  return 0;
}
void inizializza(int m[][MAX], int max){
	int c1, c2;
	c1=0;
	while(c1 < max){
		c2=0;
		while (c2 < MAX){
			m[c1][c2] = (c1+1)*(c2+1);
			c2=c2+1;
		}
		c1=c1+1;
	}
}

void visualizza(int m[][MAX], int max){
	int c1, c2;
	printf("Questa e' la tavola pitagorica:\n");
	c1=0;
	while (c1 < max){
		c2=0;
		while(c2 < MAX){
			printf("\t%d", m[c1][c2]);
			c2=c2+1;
		}
		printf("\n");
		c1=c1+1;
	}
}