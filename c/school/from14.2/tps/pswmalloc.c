/*Lorenzo Cauli 3C
scopo: generare randomicamente una password tramite allocazione dinamica e aritmetica puntatori
*/

#define MAX 20
#define MIN 5

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rnd(int min, int max);
char* riserva(int n);
void init(char* out, int len);
void pwinit(char* out, int len, char* stn);
void visual(char* psw, int len);

int main(){
	srand(time(NULL));
	int pwl = rnd(MIN, MAX);		//declare e init lunghezza password
	char* psw; char* sten;			//declare puntatori a vettori dinamici
	psw = riserva(pwl);			//allocazione vettore password
	sten = riserva(pwl);			//allocazione vettore stencil password
	init(sten, pwl);			//init vettore stencil
	pwinit(psw, pwl, sten);			//init vettore password
	visual(psw, pwl);			//visualizzazione password
	free(psw); free(sten);			//rilascio memoria
	return 0;
}

int rnd(int min, int max){
	return rand()%(max-min+1)+min;
}

char* riserva(int n){
	char* out;
	out = (char*)malloc(sizeof(char) * n);
	if (out == NULL) {
		printf("Errore nell'allocazione memoria.\n"); exit(-1);
	}
	return out;
}

void init(char* out, int len){
	char pal[]={'C', 'c', 'n', '\0'};		//declare e init vettore palette
	char* app; app = out;				//declare e init puntatore appoggio
	while ( app < out + len){			//ciclo assegnazione valore allo stencil
		*app = pal[rnd(0, 2)];			//assegnazione valore stencil tramite posizione casuale del vettore palette
		app++;					//incremento puntatore appoggio
	}
}

void pwinit(char* out, int len, char* stn){
	char* app;  app = out;					//declare e init puntatore appoggio password
	char* app2; app2 = stn;					//declare e init puntatore appoggio stencil
	while ( app < out && app2 < stn){			//ciclo assegnazione caratteri casuali password
		if (*app2 == 'C') *app = rnd('A', 'Z');		//se il carattere in stencil e' C allora quella posizione della password sara' un carattere maiuscolo
		else if (*app2 == 'c') *app = rnd('a', 'z');	//stessa cosa ma con carattere minuscolo se sten e' c
		else *app = rnd('0', '9');			//stessa cosa ma con numero se sten e' n
		app++; app2++;					//incremento puntatori
	}
}

void visual(char* psw, int len){
	char* app; app = psw;
	while ( app < psw + len){
		printf("%c", *app);
		app++;
	}
	printf("\n");
}
