#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

void lista_inserir_no_ordenado(No *L, No *no) {
    No *anterior = L;
    No *atual = L->prox;

    while (atual != NULL && atual->valor < no->valor) {
        anterior = atual;
        atual = atual->prox;
    }

    anterior->prox = no;
    no->prox = atual;
}

void inserir_valor_lista_ordenada(No *lista_ordenada, float valor) {
    No *novo_no = (No *)malloc(sizeof(No));
    if (novo_no == NULL) {
        printf("Falha ao alocar memória\n");
        exit(1);
    }
    novo_no->valor = valor;
    novo_no->prox = NULL;
    lista_inserir_no_ordenado(lista_ordenada, novo_no);
}

void inserir_valor_lista_nao_ordenada(No *lista_nao_ordenada, float valor) {
    No *novo_no = (No *)malloc(sizeof(No));
    if (novo_no == NULL) {
        printf("Falha ao alocar memória\n");
        exit(1);
    }
    novo_no->valor = valor;
    novo_no->prox = lista_nao_ordenada->prox;
    lista_nao_ordenada->prox = novo_no;
}