#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int* mealoc(int n){
    int *p = malloc(n*sizeof(int)), *q;
    for (q=p; q<=p+n; q++) *q = 0;
    return p;
}

int main(int argc, char** argv) {

}

