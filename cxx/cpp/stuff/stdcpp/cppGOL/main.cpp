#include <iostream>
#include <162lib.h> 
#include <ncurses.h>
#include "classes.hpp"


#define HDIM 30
#define VDIM 30


int main(int argc, char** argv){
	//declare generations count, default to 100 if no args given
	//else use first arg as generations count
	unsigned int gens = 100;
	if (argc > 1) gens = std::stoi(argv[1]);
	//declare chamber object with width and height as parameters
	GOLChamber camere(10, 10); 
	//initialize rng
	srand(time(NULL));
	initscr();

	noecho();
	//create gen 0
	camere.rndGen();
	//dump chamber contents to console
	camere.dump();
	//advange to gen i
	for (unsigned int cnt = 0; cnt < gens; cnt++) {
		camere.advGen();
		camere.ncdump();
		getch();
	}


	endwin();
	return 0;
}

	
