#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(int argc, char* argv[]){

    No* n0 = no('C', NULL);
    No* n1 = no('I', NULL);
    No* n2 = no('A', no('D', no('B', no('X', no('Z', NULL)))));
    No* n3 = no('U', NULL);
    
    lista_inserir_no(n0, n2);
    lista_inserir_no(n0, n1);
    lista_inserir_no(n0, n3);
    lista_imprimir(n0);
    printf("\nqtd nos: %d", lista_quantidade_nos(n0));
    No* n_copia = lista_copiar(n0);
    printf("\n");
    lista_imprimir(n_copia);
    lista_concatenar(n0, n_copia);
    printf("\n");
    lista_imprimir(n0);
    lista_liberar(n0);
    n0 = NULL;
    lista_imprimir(n0);

    printf("\nO caractere está presente? %d", lista_verificar_existencia(n0, 'I'));
    printf("\nNum de vezes: %d", lista_verificar_ocorrencias(n0,'I'));
    lista_imprimir_inversa(n0);
    lista_remover_no_i(n0, 1);
        printf("\n");
        lista_imprimir(n0);
    lista_remover_no(n0, 'A');
    lista_liberar(n0);
        printf("\n");
        lista_imprimir(n0);


    exit(0);
}