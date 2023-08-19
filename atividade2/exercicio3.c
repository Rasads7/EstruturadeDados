#include <stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]){

    char v[3] = {"texto", "J", "EDA"}, a[1] = {"EDO"};
    int b = 0;

    for(int i = 0; i < 3; i++){
        if(v[i] == a[0]){
            b++;
        }
}

    printf("O numero de vezes que aparece no vetor e: %d", b);

    return 0;
}