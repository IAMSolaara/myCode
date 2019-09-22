//Lorenzo Cauli 4Cinf, 19/09/2019

#include <stdio.h>
//my library here is just used for the fileOpen func
#include <162lib.h>

//dimension constants
#define HDIM 50
#define VDIM 25

void loadFromFileIntoBDArray(const int w, const int h, int out[w][h], FILE* inFile, int* wout, int* hout);
void dumpBDArray(const int w, const int h, const int weff, const int heff, int v[w][h]);
void initBDArray(const int w, const int h, int out[w][h]);
void modifyFromFileIntoBDArray(const int w, const int h, const int weff, const int heff, int out[w][h], FILE* inFile);
void dumpBDArrayToFile(const int w, const int h, const int weff, const int heff, int v[w][h], FILE* outFile);

int main(){
  int weff, heff;  //dimension variables declaration

  //open file streams
  FILE* image = fileOpen("immagine.txt", "r");
  FILE* mod = fileOpen("modifica.txt", "r");
  FILE* result = fileOpen("immagine2.txt", "w+");

  int imageArray[HDIM][VDIM];  //declare bi-dimensional array

  //initialize array full of -1s
  initBDArray(HDIM, VDIM, imageArray);
  //load data from file into array, also returns array used dimension
  loadFromFileIntoBDArray(HDIM, VDIM, imageArray, image, &weff, &heff);
  //dump array contents to shell
  dumpBDArray(HDIM, VDIM, weff, heff, imageArray);
  //apply modifications from file into array
  modifyFromFileIntoBDArray(HDIM, VDIM, weff, heff, imageArray, mod);
  //dump again to check results
  dumpBDArray(HDIM, VDIM, weff, heff, imageArray);
  //save results to another file
  dumpBDArrayToFile(HDIM, VDIM, weff, heff, imageArray, result);

  //close file streams
  fclose(image);
  fclose(mod);
  fclose(result);

  return 0;
}

void loadFromFileIntoBDArray(const int w, const int h, int out[w][h], FILE* inFile, int* wout, int* hout){
  //declare and init temporary variables to use as index coordinates and value to give to array
  int xtmp, ytmp;
  int vtmp;
  xtmp = 0;
  ytmp = 0;
  vtmp = 0;

  for (int i = 0; i < w; i++) {  //rows loop
    for (int j = 0; j < h; j++) {  //coloumns loop
      if (fscanf(inFile, "%d%*c", &xtmp) != EOF){  //check if got to end of file and at the same time get x value
        fscanf(inFile, "%d%*c", &ytmp);  //get y value
        fscanf(inFile, "%d%*c", &vtmp);  //get actual value to put into array
        out[xtmp][ytmp] = vtmp;  //put said value into array
      }
    }
  }
  *wout = xtmp + 1;  //return used array width
  *hout = ytmp + 1;  //same but height
}

void modifyFromFileIntoBDArray(const int w, const int h, const int weff, const int heff, int out[w][h], FILE* inFile){
  int vtmp = 0;  //declare temp variables for value to get and number of rejected entries
  int rejected = 0;

  for (int i = 0; i < weff; i++) {  //rows loop
    for (int j = 0; j < heff; j++) {  //coloumns loop
      if (fscanf(inFile, "%d%*c", &vtmp) != EOF){  //EOF check and get value
        //check if resulting value would be out of bounds, memorize it if in bounds
        if (out[i][j] + vtmp >= 0 && out[i][j] + vtmp <= 255) out[i][j] += vtmp;
        else rejected++;  //increment rejected counter if resoult is OOB
      }
    }
  }
  //if we got any rejected value, tell the used about it
  if (rejected > 0) printf("Rejected %d modification(s) due to resulting value being out of bounds.\n", rejected);
}

void initBDArray(const int w, const int h, int out[w][h]){
  for (int i = 0; i < w; i++) {  //rows loop
    for (int j = 0; j < h; j++) {  //coloumns loop
      out[i][j] = -1;  //init cell to -1
    }
  }
}

void dumpBDArray(const int w, const int h, const int weff, const int heff, int v[w][h]){
  for (int i = 0; i < weff; i++){  //rows loop
    for (int j = 0; j < heff; j++){  //coloumns loop
      if (v[i][j] != -1) printf(" %d ", v[i][j]);  //if cell isnt at default value, print its contents
    }
    printf("\n");  //newline to end row
  }
  printf("\n");  //newline for good manners
}

void dumpBDArrayToFile(const int w, const int h, const int weff, const int heff, int v[w][h], FILE* outFile){
  for (int i = 0; i < weff; i++){  //rows loop
    for (int j = 0; j < heff; j++){  //coloumns loop
      //if cell isnt at default value, print its contents into file
      if (v[i][j] != -1) fprintf(outFile, " %d ", v[i][j]);
    }
    fprintf(outFile, "\n");  //newline to end row
  }
  fprintf(outFile, "\n");  //newline for good measure
}
