#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "pilha.h"

int main(){

    No1 *remover;
    Pilha p;
    int opcao;

    criar_pilha(&p);

    No *r;
    Fila fila;
    int opcao2, valor;

    criar_fila(&fila);

    printf("Escolha se quer usar a pilha(1) ou fila(2): ");
    scanf("%d", &opcao2);

    if(opcao2 == 1){
    do{
        printf("\n0 - Sair\n1 - Empilhar\n2 - Desempilhar\n3 - Impirmir\n");
        scanf("%d", &opcao);
        getchar();
        printf("\nOpcao: %d\n", opcao);

        switch(opcao){
            case 1:
            empilhar(&p);
            break;
            case 2:
            remover = desempilhar(&p);
            if(remover){
                printf("\nElemento removido com sucesso!\n");
                imprimir_pessoa(remover->p);

                free(remover);
            }else{
                printf("\nSem no a remover.\n");
            }
            break;
            case 3:
            imprimir_pilha(&p);
            break;
            default:
            if(opcao != 0){
                printf("\nOpcao invalida!!\n");
            }
        }
    }while(opcao !=0);
    }

    if(opcao2 == 2){
        do{
        printf("\n0 - Sair\n1 - Inserir\n2 - Remover\n3 - Imprimir\n");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserir_na_fila(&fila, valor);
            break;
            case 2:
            r = remover_na_fila(&fila);
            if(r){
                printf("Removido: %d\n", r->valor);
                free(r);
            }
            break;
            case 3:
            imprimir(&fila);
            break;
            default:
            if (opcao != 0){
                printf("\nOpcao invalida\n");
            }
        }

    }while (opcao != 0);
    }

    return 0;
}