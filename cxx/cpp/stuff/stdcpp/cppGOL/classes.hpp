#ifndef GOLCHAMBER_H
#define GOLCHAMBER_H
class GOLChamber{
	unsigned int width = 0;
	unsigned int height = 0;
	char* chamber = NULL;
	char* prevChamber = NULL;

	public:
	GOLChamber(unsigned int w, unsigned int h){
		width = w;
		height = h;
		chamber = new char[width*height];
		prevChamber = new char[width*height];
	}

	~GOLChamber(){
		delete [] chamber;
	}
	void rndGen(){
		for (unsigned int i = 0; i < width; i++) {
			for (unsigned int j = 0; j < height; j++) {
				chamber[i*width+j] = (rnd(0, 1)) ? ' ' : '#';
			}
		}
	}

	void dump(){
		for (unsigned int i = 0; i < width; i++){
			for (unsigned int j = 0; j < height; j++) {
				std::cout << " " << chamber[i*width+j] << " ";
			}
			std::cout << "\n";
		}
		std::cout << "\n";
	}

	void ncdump(){
		for (unsigned int i = 0; i < width; i++){
			for (unsigned int j = 0; j < height; j++) {
				mvaddch(i, j, chamber[i*width+j]);
			}
		}
		refresh();
	}
	void advGen(){
		int curNeighbors = 0;
		copyChamber();
		for (unsigned int i = 1; i < width - 1; i++) {
			for (unsigned int j = 1; j < height - 1; j++) {
				curNeighbors = countNeighbors(i, j);
				if (chamber[i*width+j] == ' ') { //current cell dead
					if (curNeighbors == 3) chamber[i*width+j] = '#';
				}

				if (chamber[i*width+j] == '#') { //current cell living
					if (curNeighbors < 2 ) chamber[i*width+j] = ' ';
					else if (curNeighbors > 3 ) chamber[i*width+j] = ' ';
				}
			}
		}
	}
	
	unsigned int countNeighbors(unsigned int x, unsigned int y){
		unsigned int cnt = 0;
		
		for (unsigned int i = x - 1; i <= x + 1; i++) {
			for (unsigned int j = y - 1; j <= y + 1; j++) {
				if (i != x && j != y){
					if (prevChamber[i*width+j] == '#') cnt++;
				}
			}
		}
		return cnt;
	}

	void copyChamber(){
		for (unsigned int i = 0; i < width; i++) {
			for (unsigned int j = 0; j < height; j++) {
				prevChamber[i*width+j] = chamber[i*width+j];
			}
		}
	}
};
#endif
