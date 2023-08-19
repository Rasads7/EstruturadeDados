#include <stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]){

    int v[8] = {5, 7, 9, 6, 7, 11, 6, 5}, a, b = 0;

    printf("Digite um numero inteiro: ");
    scanf("%d", &a);

    for(int i = 0; i < 8; i++){
        if(v[i] == a){
            b++;
        }
}

    printf("O numero aparece: %d vezes no vetor", b);

    return 0;
}