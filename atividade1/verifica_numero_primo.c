#include <stdio.h>
#include<stdlib.h>


int verificanumero(int num) {
    if (num <= 1) {
        return 0;  
    }
    
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;  
        }
    }
    
    return 1; 
}

int main() {
    int num;

    printf("Digite um número: ");
    scanf("%d", &num);

    if (verificanumero(num)) {
        printf("1 - O número eh primo.\n");
    } else {
        printf("0 - O número nao eh primo.\n");
    }

    return 0;
}