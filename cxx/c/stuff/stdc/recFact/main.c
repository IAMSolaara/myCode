#include <stdio.h>

int fact(int x) {
	int out;
	if (x > 1) {
		out = x * fact(x-1);
	}
	else out = 1;
	return out;
}

int main(){
	int x = 5;

	printf("initial number: %d\n", x);

	printf("%d factorial: %d", x, fact(x));

}
