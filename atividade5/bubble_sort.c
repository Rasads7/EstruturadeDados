#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubbleSort(char *array[], int n) {
    int i, j;
    char *temp;

    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (strcmp(array[j], array[j+1]) > 0) {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    
    if (argc != 2) {
        printf("Uso: %s <arquivo_palavras>\n", argv[0]);
        
        return 1;
    }
    
    FILE *arquivo_entrada = fopen(argv[1], "r");
    if (arquivo_entrada == NULL) {
        printf("Erro ao abrir o arquivo %s\n", argv[1]);
        
        return 1;
    }
    
    char palavra[100];
    int quantidade_palavras = 0;
    while (fgets(palavra, sizeof(palavra), arquivo_entrada) != NULL) {
        quantidade_palavras++;
    }
    
    fseek(arquivo_entrada, 0, SEEK_SET);
    
    char **palavras = (char**) malloc(quantidade_palavras * sizeof(char*));
    
    if (palavras == NULL) {
        printf("Erro ao alocar memória\n");
        
        return 1;
    }
    
    int i = 0;
    while (fgets(palavra, sizeof(palavra), arquivo_entrada) != NULL) {
        palavra[strcspn(palavra, "\n")] = '\0';
        palavras[i] = strdup(palavra);
        i++;
    }

    fclose(arquivo_entrada);

    bubbleSort(palavras, quantidade_palavras);

    char nome_arquivo_saida[100];
    strncpy(nome_arquivo_saida, argv[1], sizeof(nome_arquivo_saida)-1);
    nome_arquivo_saida[sizeof(nome_arquivo_saida)-1] = '\0';
    strcat(nome_arquivo_saida, "_ordenado.txt");

    FILE *arquivo_saida = fopen(nome_arquivo_saida, "w");
    if (arquivo_saida == NULL) {
        printf("Erro ao criar o arquivo de saída\n");
        return 1;
    }

    for (i = 0; i < quantidade_palavras; i++) {
        fprintf(arquivo_saida, "%s\n", palavras[i]);
    }

    fclose(arquivo_saida);

    for (i = 0; i < quantidade_palavras; i++) {
        free(palavras[i]);
    }
    
    free(palavras);

    printf("%s\n", nome_arquivo_saida);

    return 0;
}