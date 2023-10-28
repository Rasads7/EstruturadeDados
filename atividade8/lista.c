#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

No* no(char valor, No* proximo_no){
    No* no = malloc(sizeof(No));
    no->valor = valor;
    no->proximo_no = proximo_no;
    return no;
}

void lista_inserir_no(No* L, No* no){
    if(L != NULL){
        if(L->proximo_no == NULL){
            L->proximo_no = no;
        }
        else{
            lista_inserir_no(L->proximo_no, no);
        }
    }
}

void lista_imprimir(No* L){
    if(L != NULL){
        printf("%c ", L->valor);
        lista_imprimir(L->proximo_no);
    }
}

int lista_quantidade_nos(No* L){
    if(L != NULL){
        return 1 + lista_quantidade_nos(L->proximo_no);
    }
    return 0;
}

No* lista_copiar(No* L){
    if(L != NULL){
        return no(L->valor, lista_copiar(L->proximo_no));
    }
    return NULL;
}

void lista_concatenar(No* L, No* Lc){
    lista_inserir_no(L, Lc);
}

void lista_liberar(No* L){
    if(L != NULL){
        lista_liberar(L->proximo_no);
        free(L);
    }
}

int lista_verificar_existencia(No* L, char valor_busca){
    int valor_existe = 0;

    if(L != NULL){
        if (L->valor == valor_busca){
            valor_existe = 1;
        } else {
            valor_existe = lista_verificar_existencia(L->proximo_no, valor_busca);
        }
    }

    return valor_existe;
}

int lista_verificar_ocorrencias(No* L, char valor_busca){
    int valor_ocorrencias = 0;

    if(L != NULL){
        if(L->valor == valor_busca){
            valor_ocorrencias = 1 + lista_verificar_ocorrencias(L->proximo_no,valor_busca);
        } else {
            valor_ocorrencias = lista_verificar_ocorrencias(L->proximo_no, valor_busca);
        }
    }

    return valor_ocorrencias;
}

void lista_imprimir_inversa(No* L){
    No* L_inverso;

    if(L->proximo_no != NULL){
        lista_imprimir_inversa(L->proximo_no);
        printf("%c ", L->valor);
    } else {
        printf("\n%c ", L->valor);
    }
}

void lista_inserir_no_i(No* L, int i){

}

void lista_remover_no_i(No* L, int i){
    if (L != NULL && i >= 0) {
        if (i == 0 && L->proximo_no != NULL) {
            No* no_remover = L->proximo_no;
            L->proximo_no = L->proximo_no->proximo_no;
            free(no_remover);
        } else {
            lista_remover_no_i(L->proximo_no, i - 1);
        }
    }    
}

void lista_remover_no(No* L, char valor_busca) {
    if (L != NULL) {
        if (L->proximo_no != NULL && L->proximo_no->valor == valor_busca) {
            No* no_remover = L->proximo_no;
            L->proximo_no = L->proximo_no->proximo_no;
            free(no_remover);
        } else {
            lista_remover_no(L->proximo_no, valor_busca);
        }
    }
}