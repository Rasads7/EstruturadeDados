#include <stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]){

    int v[4] = {5,7,9,6}, a = 0, b = 0;

    for(int i = 0; i < 4; i++){
        b = v[i] + a;
        a = b;
    }

    printf("%d", b);

    return 0;
}