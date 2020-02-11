#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

#define HEIGHT 25
#define WIDTH 80

double parabolaWizard(double x, double width, double height){
	double out = 0;
	
	double a = -1;
	//double b = abs(a) * 2;
	double b = 2;

	return (a*(x*x))+(b*x);
}

double calculateParabola(double x, double a, double b){
	return (a*(x*x))+(b*x);
}

int main(){
	printf("\e[2J");

	int x = 0;
	int y = 0;
	int rx = 0;
	int ry = 0;

	for (int i = 0; i < 10; i++) {
		x = i;
		y = (int)calculateParabola(x, 1, 1);

		rx = x;
		ry = HEIGHT-y;

		printf("\e[%i;%iH*", ry, rx);
	}

	return 0;
}

