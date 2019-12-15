#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int foo(int a){
    return a++;
}

int bar(char arr[]){
    char arr_2[50];
    return sizeof(arr)+sizeof(arr_2);
}

int baz(){
    char arr[10]; int s = bar(arr);
    int result = 0;
    for (int i = 0; i<5; ++i){
        result += foo(i);
    }
    result += s;
    return result;
}

int main(int argc, char** argv) {
    printf("%d", baz());
}

