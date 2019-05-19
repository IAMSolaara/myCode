/*Lorenzo Cauli 3C 4-12-2018
scopo: confrontare 3 fattorie e comunicare dove andrà il veterinario.
dati:
	stall1	I	int	stall1 > 0
	stall2	I	int	stall2 > 0
*/
#include<stdio.h>

void leggi(const char msg[], const char msg2[], int* st1, int* st2);
void sum(int* farm, int st1, int st2);
void mmconf(int* max, int f1, int f2, int f3);
void comm(const char msg[], int f1, int f2, int f3, int max);

int main(){
	int farm1, farm2, farm3, stall1, stall2, max;
	leggi("Quanti animali ci sono nella stalla 1 in fattoria 1?\n","Quanti animali ci sono nella stalla 2 in fattoria 1?\n", &stall1, &stall2);
	sum(&farm1, stall1, stall2);
	leggi("Quanti animali ci sono nella stalla 1 in fattoria 2?\n","Quanti animali ci sono nella stalla 2 in fattoria 2?\n", &stall1, &stall2);
        sum(&farm2, stall1, stall2);
	leggi("Quanti animali ci sono nella stalla 1 in fattoria 3?\n","Quanti animali ci sono nella stalla 2 in fattoria 3?\n", &stall1, &stall2);
        sum(&farm3, stall1, stall2);
	mmconf(&max, farm1, farm2, farm3);
	comm("Il veterinario andrà nella fattoria", farm1, farm2, farm3, max);
return 0;
}

void leggi(const char msg[], const char msg2[], int* st1, int* st2){
        printf("%s", msg); scanf("%d", st1);
        while (*st1 <= 0) {printf("Numero non valido, inserirne un altro.\n"); scanf("%d", st1);}
        printf("%s", msg2); scanf("%d", st2);
        while (*st2 <= 0) {printf("Numero non valido, inserirne un altro.\n"); scanf("%d", st2);}
}

void sum(int* farm, int st1, int st2){
        *farm = st1 + st2;
}

void mmconf(int* max, int f1, int f2, int f3){
        *max = f1;
        if (f2 > *max) *max = f2;
        else if (f3 > *max) *max = f3;
}

void comm(const char msg[], int f1, int f2, int f3, int max){
        if (max == f1) printf("%s 1.\n", msg);
        if (max == f2) printf("%s 2.\n", msg);
        if (max == f3) printf("%s 3.\n", msg);
}
