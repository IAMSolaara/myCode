/*Lorenzo Cauli 3C 13-11-2018*/

#include <stdio.h>
#define MAX 11
int main() {
	int c,r,num;
	num=c=r=1;
	while (c < MAX && r < MAX) {
		num=c*r;printf("%d\t", num); c++; if (c==MAX) {printf("\n"); r++; c=1;}}
return 0;
}

