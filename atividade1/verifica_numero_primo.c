#include <stdio.h>

int verifica_numero_primo(int n){
    return 0;
}

int main(int argc, char* argv[]){

    int num, i, resultado;

    printf("teste");

    num = argv[1];
    
    printf("\n%s\n", argv[1]);

for (i = 2; i <= num / 2; i++) {
    if (num % i == 0) {
       resultado++;
       break;
    }
 }
 
 if (resultado == 0){
    printf("%d é um número primo\n", num);
 }else{
    printf("%s não é um número primo\n", num);
 }
 
 return 0;
}
