#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int dia, mes, ano;
}Data;

typedef struct{
    char nome[50];
    Data data;
}Pessoa;

typedef struct no1{
    Pessoa p;
    struct no1 *proximo;
}No1;

typedef struct {
    No1 *topo;
    int tam;
}Pilha;

void criar_pilha(Pilha *p){
    p->topo = NULL;
    p->tam = 0;
}

Pessoa ler_pessoa(){
    Pessoa p;

    printf("\nDigite o nome e data de nascimento:\n");
    scanf("%49[^\n]%d%d%d", p.nome, &p.data.dia, &p.data.mes, &p.data.ano);

    return p;
}

void imprimir_pessoa(Pessoa p){
    printf("\nNome: %s\nData: %2d/%2d/%4d\n", p.nome, p.data.dia, p.data.mes, p.data.ano);
}

void empilhar(Pilha *p){
    No1 *novo = malloc(sizeof(No1));

    if (novo){
        novo->p = ler_pessoa();
        novo->proximo = p->topo;
        p->topo = novo;
        p->tam++;
    } else{
        printf("\nErro ao alocar memoria");
    }
}

No1* desempilhar(Pilha *p){
    if(p->topo){
        No1 *remover = p->topo;
        p->topo = remover->proximo;
        p->tam--;
        return remover;
    }else{
        printf("\nPilha vazia!\n");
        return NULL;
    }
}

void imprimir_pilha(Pilha *p){
    No1 *aux = p->topo;
    printf("----------PILHA Tam: %d----------", p->tam);
    while(aux){
        imprimir_pessoa(aux->p);
        aux = aux->proximo;
    }
    printf("----------FIM DA PILHA----------");
}


int main(){

    No1 *remover;
    Pilha p;
    int opcao;

    criar_pilha(&p);

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

    return 0;
}