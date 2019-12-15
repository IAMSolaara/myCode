#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char** argv) {

    //questiona burda
    int a=0x12, b = &a;
    int c = (a++, a-=3) < (++*&*&*b);
    printf("%d %d\n", a, c);
}