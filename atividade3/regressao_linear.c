#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int x;
    float y;
} Ponto;

double calcular_media(double* valores, int n) {
    double soma = 0;
    for (int i = 0; i < n; i++) {
        soma += valores[i];
    }
    return soma / n;
}

double calcular_coeficiente(Ponto* pontos, int n, double media_x, double media_y) {
    double numerador = 0;
    double denominador = 0;
    
    for (int i = 0; i < n; i++) {
        numerador += (pontos[i].x - media_x) * (pontos[i].y - media_y);
        denominador += (pontos[i].x - media_x) * (pontos[i].x - media_x);
    }
    
    return numerador / denominador;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <.csv>\n", argv[0]);
        return 1;
    }

    FILE *arquivo = fopen(argv[1], "r");
    if (arquivo == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
        return 1;
    }

    int num_pontos = 0;
    fscanf(arquivo, "%d", &num_pontos);

    Ponto *pontos = (Ponto *)malloc(num_pontos * sizeof(Ponto));
    if (pontos == NULL) {
        printf("Erro na alocação de memória.\n");
        return 1;
    }

    for (int i = 0; i < num_pontos; i++) {
        fscanf(arquivo, "%d,%.2f", &pontos[i].x, &pontos[i].y);
    }

    
    return 0;
}