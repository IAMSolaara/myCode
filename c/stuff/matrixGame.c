//libraries for: printing stuff, random number generation and input scan
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

//game parameters defines
#define FIELDH 23					//field height
#define FIELDW 80					//field width
#define DISPW 40					//display width
#define CHARPOSX DISPW/2			//character position x coordinates
#define CHARPOSY FIELDH/2			//character position y coordinates
#define REFRBASE 500000000			//base refresh, got it to around 1Hz
#define REFRESH REFRBASE / 30		//refresh divider, now set to 30Hz
#define BGCHAR 32					//background character, 176 DOS
#define PCCHAR 35					//player character, 219 DOS
#define PIPECHAR 124				//pipe character, 186 DOS
#define PIPEWIDTH 2					//pipe width
#define PIPEMAXHEIGHT (FIELDH/2)-2	//maximum pipe height
#define PIPEDISTANCE 3				//distance between pipes

int getch();											//used in input scan, unused for now
int system(const char* commmand);						//used for system commands, will be used to set console window size
void fieldPrt(char f[][FIELDW], int s);					//used for printing the field
void fieldInit(char f[][FIELDW], int* pp);				//used for field init
void fieldMove(char f[][FIELDW], int s, int* pp);		//main field draw and refresh function
void fieldMirror(char dir, char f[][FIELDW]);			//mirror field function, unused
void fieldShiftRight(char f[][FIELDW]);					//field shifting function, used in movement
void tubeGen(char f[][FIELDW], int* pp);				//pipe generation function, now incomplete

int main(){
	srand(time(NULL)); 													//random number generator init
	char field[FIELDH][FIELDW]; int pipepos=0, score=0;					//various declares: field matrix, pipe position and score, the latter is not yet implemented 
	fieldInit(field, &pipepos);											//field init
	fieldMove(field, score, &pipepos);									//the refresh and movement function is now entered
return 0;
}

void fieldPrt(char f[][FIELDW], int s){
	printf("Score: %d\n", s);			//print score
	int i=0, k=0;						//declare variables used as coordinates for printing the matrix
	while (i < FIELDH){					//main line print cycle
		k=0;							//zerofill of coloumn variable
		while(k < DISPW){				//child cycle
			printf("%c", f[i][k]);		//print matrix using i and k as indexes
			k++;						//coloumn counter increment
		}
		printf("\n");					//print a newline after line is printed to begin printing next one
		i++;							//line counter increment
	}
}
void fieldInit(char f[][FIELDW], int* pp){
	int i=0, k=0;						//declare variables used as coordinates for init-ing matrix cells
	while (i < FIELDH){					//main line init cycle
		k=0;							//zerofill of coloumn variable
		while(k < FIELDW){				//child cycle
			f[i][k]=BGCHAR;				//init of all cells to background character
			k++;						//coloumn counter increment
		}
		i++;							//line counter increment
	}
	f[CHARPOSY][CHARPOSX]=PCCHAR;		//init player cell to player character
}
void fieldMove(char f[][FIELDW], int s, int* pp){
	int clk=0;							//declare clock variable, used in timing management
	while (1){							//infinite screen print cycle
		if (clk > REFRESH){				//if clock var is higher than REFRESH constant, a determined amount of time must have passed, in which the cycle goes "idle"
			tubeGen(f, pp);				//generate tubes
			fieldShiftRight(f);			//shift field right for movement
			fieldPrt(f, s);				//print new screen
			clk=0;						//zerofill clock
		}
		clk++;							//clock variable increment
	}
}
int getch() {										//function not made by me, will study it better when implementing input
	struct termios oldattr, newattr;
	int ch;
	tcgetattr( STDIN_FILENO, &oldattr );
	newattr = oldattr;
	newattr.c_lflag &= ~( ICANON | ECHO );
	tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
	ch = getchar();
	tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
	return ch;
}
void fieldMirror(char dir, char f[][FIELDW]){		//function deprecated, will remove it later
	int i=0, j=0, vc=0; char tmp[FIELDW];
	/*up shift*/
	if (dir == 'v') {
	while (vc < FIELDW){
		tmp[vc]=f[0][vc];
		vc++;
	}
	while (i < FIELDW) {
		f[0][i]=f[FIELDH-1][i];
		i++;
	}
	while (j < FIELDW) {
		f[FIELDH-1][j]=tmp[j];
		j++;
	}
	}
	/*left shift*/
		if (dir == 'h') {
		while (vc < FIELDH){
			tmp[vc]=f[vc][0];
			vc++;
		}
		while (i < FIELDH) {
			f[i][0]=f[i][FIELDW-1];
			i++;
		}
		while (j < FIELDH) {
			f[j][FIELDW-1]=tmp[j];
			j++;
		}
	}
}
void fieldShiftRight(char f[][FIELDW]){
	int mx, my=0;											//declare coordinates variables used in field shifting
	char tmp;												//declare temporary char for shifting
	while (my<FIELDH){										//main coloumn cycle
		mx=1;												//init x to one, since zero will break function as there wouldnt be previous position 
		while(mx<FIELDW && mx > 0 && my != CHARPOSY){		//main line-based swap cycle
			tmp=f[my][mx];									//dump destination char into temp backup var
			f[my][mx]=f[my][mx-1];							//put source into destination
			f[my][mx-1]=tmp;								//restore destination into source, swapping the two chars
			mx++;											//x variable increment
		}
		my++;												//y variable increment
	}	
}
void tubeGen(char f[][FIELDW], int* pp){					//will document when function is fully working		
	int pc=*pp, i=0, j=0, height, gs=0;
	while(gs == 0 && pc < FIELDW){
		height=rand()%(PIPEMAXHEIGHT)+1;
		j=pc;
		while (j < PIPEWIDTH+PIPEDISTANCE){
			i=0;
			if (j < PIPEWIDTH) {
				while(i<height){
					f[i][j]=PIPECHAR;
					i++;
				}
			}
			else if (j >= PIPEWIDTH) {
				while(i<height){
					f[i][j]=PCCHAR;
					i++;
				}
			}
			j++;
		}
		pc++;
		if (pc >= FIELDW) gs=1;
	}
}