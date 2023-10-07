typedef struct no{
    int valor;
    struct no *proximo;
}No;

typedef struct{
    No *prim;
    No *fim;
    int tam;
}Fila;

void criar_fila(Fila *fila){
    fila->prim = NULL;
    fila->fim = NULL;
    fila->tam = 0;
}

void inserir_na_fila(Fila *fila, int num){
    No aux, *novo = malloc(sizeof(No));
    if(novo){
        novo->valor = num;
        novo->proximo = NULL;
        if(fila->prim == NULL){
            fila->prim = novo;
            fila->fim = novo;
        }else{
            fila->fim->proximo = novo;
            fila->fim = novo;
        }
        fila->tam++;
    }else{
        printf("\nErro ao alocar memoria\n");
    }
}

No* remover_na_fila(Fila *fila){
    No *remover = NULL;

    if(fila->prim){
        remover = fila->prim;
        fila->prim = remover->proximo;
        fila->tam--;
    }else{
        printf("\nFila vazia\n");
    }
    return remover;
}

void imprimir(Fila *fila){
    No *aux = fila->prim;
    printf("\n----------FILA----------\n");
    while(aux){
        printf("%d  ", aux->valor);
        aux = aux->proximo;
    }
    printf("\n----------FIM DA FILA----------\n");
}