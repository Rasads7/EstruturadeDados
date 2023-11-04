#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "lista.h"

int main() {
    No lista_n_ordenada;
    No lista_ordenada;
    lista_n_ordenada.prox = NULL;
    lista_ordenada.prox = NULL;

    FILE *arquivo = fopen("1kk_rand_float.csv", "r");
    if (arquivo == NULL) {
        printf("Erro: Não foi possível abrir o arquivo.\n");
        return 1;
    }

    char linha[20];
    float valor;
    clock_t inicio, fim;
    double tempo_nao_ordenada = 0.0;
    double tempo_ordenada = 0.0;
    int num_elementos = 0;

    while (fgets(linha, sizeof(linha), arquivo)) {
        valor = strtof(linha, NULL);

        inicio = clock();
        inserir_valor_lista_n_ordenada(&lista_n_ordenada, valor);
        fim = clock();
        tempo_nao_ordenada += (double)(fim - inicio) / CLOCKS_PER_SEC;

        inicio = clock();
        inserir_valor_lista_ordenada(&lista_ordenada, valor);
        fim = clock();
        tempo_ordenada += (double)(fim - inicio) / CLOCKS_PER_SEC;

        num_elementos++;
    }

    fclose(arquivo);

    printf("Tempo médio de inserção em lista não ordenada: %lf segundos\n", tempo_nao_ordenada / num_elementos);
    printf("Tempo médio de inserção em lista ordenada: %lf segundos\n", tempo_ordenada / num_elementos);

    No *atual = lista_n_ordenada.prox;
    while (atual != NULL) {
        No *proximo = atual->prox;
        free(atual);
        atual = proximo;
    }

    atual = lista_ordenada.prox;
    while (atual != NULL) {
        No *proximo = atual->prox;
        free(atual);
        atual = proximo;
    }

    return 0;
}