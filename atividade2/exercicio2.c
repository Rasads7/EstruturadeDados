#include <stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]){

    int v[4] = {5,7,9,6}, menor, maior;
    menor = v[0];
    maior = v[0];

    for(int i = 0; i < 4; i++){
        if(v[i] < menor){
            menor = v[1];
        }
        if (v[i] > maior){
            maior = v[i];
        }
    }

    printf("Maior: %d\n", maior);
    printf("Menor: %d", menor);

    return 0;
}