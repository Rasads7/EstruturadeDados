#include <stdio.h>

double calcular_dobro(double n){
    return n*2;
}

int main(int argc, char* argv []){
    int n = 11;
    int n2 = 0;
    float f1 = 1.5;
    double d1 = 1.5555555;
    char letra = 'J';

    if(n2){
        printf("0 eh verdadeiro\n");
    }

    if(n){
        printf("11 eh verdadeiro");
    }
    printf("\n");
    for(n = 0; n < 10; n++){
        printf("%d ", n);
    }
    printf("\n");

    do{
        printf("%d ", n);
    }while (n < 10);

    printf("\nO dobro de %f eh %f", d1, calcular_dobro(d1));

    return 0;
}