#include <stdio.h>
#include <stdint.h>
#include <162lib.h>


#define HDIM 50
#define VDIM 25

void loadFromFileIntoBDArray(const int w, const int h, int out[w][h], FILE* inFile, int* wout, int* hout);
void dumpBDArray(const int w, const int h, const int weff, const int heff, int v[w][h]);
void initBDArray(const int w, const int h, int out[w][h]);
void modifyFromFileIntoBDArray(const int w, const int h, const int weff, const int heff, int out[w][h], FILE* inFile);
void dumpBDArrayToFile(const int w, const int h, const int weff, const int heff, int v[w][h], FILE* outFile);

int main(){
  int weff, heff;
  
  FILE* image = fileOpen("immagine.txt", "r");
  FILE* mod = fileOpen("modifica.txt", "r");
  FILE* result = fileOpen("immagine2.txt", "w+");

  int imageArray[HDIM][VDIM];
  
  initBDArray(HDIM, VDIM, imageArray);
  loadFromFileIntoBDArray(HDIM, VDIM, imageArray, image, &weff, &heff);
  dumpBDArray(HDIM, VDIM, weff, heff, imageArray);
  modifyFromFileIntoBDArray(HDIM, VDIM, weff, heff, imageArray, mod);
  dumpBDArray(HDIM, VDIM, weff, heff, imageArray);
  dumpBDArrayToFile(HDIM, VDIM, weff, heff, imageArray, result);
  

  fclose(image);
  fclose(mod);
  
  return 0;
}

void loadFromFileIntoBDArray(const int w, const int h, int out[w][h], FILE* inFile, int* wout, int* hout){
  int xtmp, ytmp;
  int vtmp;
  xtmp = 0;
  ytmp = 0;
  vtmp = 0;

  for (int i = 0; i < w; i++) {
    for (int j = 0; j < h; j++) {
      if (fscanf(inFile, "%d%*c", &xtmp) != EOF){
        fscanf(inFile, "%d%*c", &ytmp);
        fscanf(inFile, "%d%*c", &vtmp);
        out[xtmp][ytmp] = vtmp;
      }
    }
  }
  printf("Max x and y coords: %d %d\n", xtmp, ytmp);
  *wout = xtmp + 1;
  *hout = ytmp + 1;
}

void modifyFromFileIntoBDArray(const int w, const int h, const int weff, const int heff, int out[w][h], FILE* inFile){
  int vtmp = 0;
  int rejected = 0;

  for (int i = 0; i < weff; i++) {
    for (int j = 0; j < heff; j++) {
      if (fscanf(inFile, "%d%*c", &vtmp) != EOF){
        if (out[i][j] + vtmp >= 0 && out[i][j] + vtmp <= 255) out[i][j] += vtmp;
        else rejected++;
      }
    }
  }
  if (rejected > 0) printf("Rejected %d modification(s) due to resulting value being out of bounds.\n", rejected);
}

void initBDArray(const int w, const int h, int out[w][h]){

  for (int i = 0; i < w; i++) {
    for (int j = 0; j < h; j++) {
      out[i][j] = -1;
    }
  }
}

void dumpBDArray(const int w, const int h, const int weff, const int heff, int v[w][h]){
  for (int i = 0; i < weff; i++){
    for (int j = 0; j < heff; j++){
      if (v[i][j] != -1) printf(" %d ", v[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void dumpBDArrayToFile(const int w, const int h, const int weff, const int heff, int v[w][h], FILE* outFile){
  for (int i = 0; i < weff; i++){
    for (int j = 0; j < heff; j++){
      if (v[i][j] != -1) fprintf(outFile, " %d ", v[i][j]);
    }
    fprintf(outFile, "\n");
  }
  fprintf(outFile, "\n");

}
