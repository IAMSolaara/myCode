/*Lorenzo Cauli 3C 6-12-2018
scopo: sommare due orari
dati:
	min1	int	I	min1 >= 0
	min2	int	I	min2 >= 0
	sec1	int	I	sec1 >= 0 && sec1 < 60
	sec2	int	I	sec2 >= 0 && sec2 < 60
	mint	int	O
	sect	int	O	sect < 60
relazione tra i dati:
	mint = min1 + min2
	sect = sec1 + sec2
	se sect > 59 ---> sect = sect - 60 && mint = mint + 1
*/

#include<stdio.h>

void leggi(const char msg[], int* in);
void leggiCompreso(const char msg[], int* in);
void timeSum(int m1, int s1, int m2, int s2, int* mt, int* st);
void comm(const char msg[], int t);

int main(){
	/*dichiarazione variabili*/
	int min1, min2, sec1, sec2, mint, sect;
	/*lettura controllata tempo*/
	leggi("Inserire minuti.\n", &min1);
	leggiCompreso("Inserire secondi.\n", &sec1);
	leggi("Inserire minuti.\n", &min2);
	leggiCompreso("Inserire secondi.\n", &sec2);
	/*somma orari e arrotondamento secondi sopra i 59*/
	timeSum(min1, sec1, min2, sec2, &mint, &sect);
	/*comunicazione durata totale*/
	comm("La durata totale e' di minuti", mint);
	comm(" e di secondi", sect);
return 0;
}

void leggi(const char msg[], int* in){
        printf("%s", msg);scanf("%d", in);
        while (*in < 0) {printf("Numero non valido, inserirne un altro.\n");scanf("%d", in);}
}

void leggiCompreso(const char msg[], int* in){
        printf("%s", msg);scanf("%d", in);
        while (*in < 0 || *in >= 60) {printf("Numero non valido, inserirne un altro.\n");scanf("%d", in);}
}

void timeSum(int m1, int s1, int m2, int s2, int* mt, int* st){
        *mt = m1 + m2;
        *st = s1 + s2;
        while (*st >= 60) {*st = *st - 60;*mt = *mt + 1;}
}

void comm(const char msg[], int t){
        printf("%s %d", msg, t); printf(".\n");
}

