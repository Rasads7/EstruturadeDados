#include <stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]){

    int v1[4] = {5, 7, 9, 6}, v2[4] = {5, 7, 9, 6}, v3[4];

    for(int i = 0; i < 4; i++){
        v3[i] = v1[i] * v2[i]; 
}

    for (int i = 0; i < 4; i++){
        printf("%d\n", v3[i]);
    }

    return 0;
}