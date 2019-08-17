#include <stdio.h>
#include <gb/gb.h>

void main(){
	int num;
	num=0;
	while (1) {
		waitpad(J_A);
		num++; printf("%d\n", num);
		waitpadup();
	}
}
