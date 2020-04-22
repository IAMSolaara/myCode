#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define HEIGHT 47
#define WIDTH 170

double calculateParabola(double x, double a, double b, double c){
	return (a*(x*x))+(b*x)+c;
}

int main(int argc, char** argv){
	if (argc < 4) return -1;

	double a = atof(argv[1]);
	double b = atof(argv[2]);
	double c = atof(argv[3]);

	printf("\e[2J");

	int x = 0;
	int y = 0;
	int rx = 0;
	int ry = 0;

	for (int i = 0; i < WIDTH; i++) {
		x = i;
		y = (int)calculateParabola(x, a, b, c);

		rx = x;
		ry = -1 * y;

		if ((rx >= 0 && rx <= WIDTH) && (ry >= 0 && ry <= HEIGHT)) {
			printf("\e[%i;%iH*", ry, rx);
		}
		usleep(100000);
		fflush(stdout);
	}

	return 0;
}
