/**/

#include <stdio.h>
#include <162lib.h>

void reverse(FILE* file);
int elCount(FILE* file);

int main(){
  FILE* f;
  int nEl;
  f = fileOpen("out.dat", "r+");
  nEl = elCount(f);
  printf("%d\n", nEl);
  reverse(f);
  fclose(f);
  return 0;
}

void reverse(FILE* file){
  int pos, off, tmp, tmp2;
  pos = SEEK_SET;
  off = SEEK_END;
  while (fread(&tmp, sizeof(int), 1, file)){
    fseek(file, 2, off-1);
    tmp2 = ftell(file);
    printf("%d %d\n", tmp, tmp2);
  }  
}

int elCount(FILE* file){
  int tmp;
  int out;
  while (fread(&tmp, sizeof(int), 1, file)) out++;
  fseek(file, 1, SEEK_SET);
  return out;
}
