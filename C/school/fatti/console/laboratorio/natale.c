/*Lorenzo Cauli 3C 13-11-2018*/
#include<stdio.h>
int main(){
	int l, s, n; n=l=s=1;
	printf("Inserisca la lunghezza dell'albero in numeri.\n"); scanf("%d", &l);
	printf("   *   \n");
	while (n<l){
		if (s==1 && n<l){printf("  ***  \n");} n++;s++;
		if (s==2 && n<l){printf(" ***** \n");} n++;s--;
		if (n==l && l>=4){printf("*******\n");s=l;} else n++;
		}
return 0;
}
