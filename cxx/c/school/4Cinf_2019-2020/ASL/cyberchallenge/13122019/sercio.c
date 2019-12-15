#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int search(int* v, int n, int x){
    int a = 0, b = n;
    while (a < b) {
        int m = (a+b)/2;
        if (v[m] == x) return 1;
        if (v[m] <  x) a = m + 1;
        else b = m;
    }
    return 0;
}
int main(int argc, char** argv) {
    int test[5] = {1,4,67,100,123};
    printf("%d", search(test, 5, 4));
}

