#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    float y;
} Ponto;

void calcularRegressao(FILE *file, Ponto *pontos, int num_pontos) {
    int i;
    int somX = 0;
    float somY = 0;
    float somXY = 0;
    float somXX = 0;
    
    for (i = 0; i < num_pontos; i++) {
        fscanf(file, "%d,%f", &(pontos[i].x), &(pontos[i].y));
        somX += pontos[i].x;
        somY += pontos[i].y;
        somXY += pontos[i].x * pontos[i].y;
        somXX += pontos[i].x * pontos[i].x;
    }
    
    float avgX = (float)somX / num_pontos;
    float avgY = somY / num_pontos;
    
    float inclin = (somXY - num_pontos * avgX * avgY) / (somXX - num_pontos * avgX * avgX);
    
    float intercept = avgY - inclin * avgX;
    
    printf("y = %fx + %f\n", inclin, intercept);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Modo de uso: ./regressao <arquivo.csv>\n");
        return 1;
    }
    
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    
    int num_pontos = 0;
    char c;
    while ((c = fgetc(file)) != EOF) {
        if (c == '\n') {
            num_pontos++;
        }
    }
    rewind(file);
    
    Ponto *pontos = (Ponto *)malloc(num_pontos * sizeof(Ponto));
    if (pontos == NULL) {
        printf("Erro ao alocar memória.\n");
        fclose(file);
        return 1;
    }
    
    calcularRegressao(file, pontos, num_pontos);
    
    free(pontos);
    fclose(file);
    
    return 0;
}