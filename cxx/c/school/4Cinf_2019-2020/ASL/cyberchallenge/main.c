#include<stdio.h>
#include<stdlib.h>

int** allocateMatrix(int size);
void deallocateMatrix(int** mat, int size);
void getMatrix(int** mat, int size);
void printMatrix(int** mat, int size);
void rotateMatrix(int** mat, int** newMatrix, int size);
void zeroMatrix(int** mat, int size);

int main(){
	int** m;
	int** newMatrix;
	int size;
	int rNum;

	scanf("%d", &size);
	m = allocateMatrix(size);
	newMatrix = allocateMatrix(size);
	
	zeroMatrix(newMatrix, size);

	getMatrix(m, size);
	printMatrix(m, size);

	rotateMatrix(m, newMatrix, size);

	printMatrix(newMatrix, size);
	deallocateMatrix(m, size);
	deallocateMatrix(newMatrix, size);
}

int** allocateMatrix(int size) {
	int** out = (int**) malloc(size*sizeof(int*));
	for (int i = 0; i < size; i++) *(out+i) = (int*)malloc(size * sizeof(int));
	return out;
}

void deallocateMatrix(int** mat, int size){
	for (int i = 0; i < size; i++) {
		free( *(mat+i) );
		*(mat+i) = NULL;
	}
	free(mat);
	mat = NULL;
}

void getMatrix(int** mat, int size){
	int i,j;
	char dummy;
	for(i=0; i < size; i++) {
		j = 0;
		while (1) {
			scanf("%d%c", *(mat+i)+j, &dummy);
			if (dummy == '\n') break;
			j++;
		}
	}
}

void printMatrix(int** mat, int size){
	int i,j;
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) printf("\t%d\t", *(*(mat+i)+j));
		printf("\n");
	}
}

void rotateMatrix(int** mat, int** newMatrix, int size){

	int i, j;

	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			*( *(newMatrix+j)+(i+size-1) ) = *(*(mat+i)+j);
		}
	}
}

void zeroMatrix(int** mat, int size){
	int i, j;

	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			*(*(mat+i)+j) = 0;
		}
	}
}
