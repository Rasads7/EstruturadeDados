#include "abb.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  Node *root = NULL;
  int key;
  int keyToRemove;
  int selecao;
  int valor;

  while (selecao != 0) {

    printf("\n\n1-Inserir\n2-Remover\n3-Busca\n4-Percorrer a arvore em "
           "ordem\n5-Percorrer a arvore em pre-ordem\n6-Percorrer a arvore em "
           "pos-ordem\n7-Valores minino e maximo\n0-Sair\n");
    printf("Selecione a acao a ser realizada na árvore: ");
    scanf("%d", &selecao);

    switch (selecao) {

    // Inserção
    case 1:
      printf("\nDigite o numero a ser inserido: ");
      scanf("%d", &valor);
      root = insert(root, valor);
      printf("Valor %d adicionado da ABB", valor);
      break;

    // Remoção
    case 2:
      printf("\nDigite o numero a ser removido: ");
      scanf("%d", &keyToRemove);
      root = removeNode(root, keyToRemove);
      printf("Valor %d removido da ABB", keyToRemove);
      break;

    // Busca
    case 3:
      printf("\nDigite o numero a ser buscado: ");
      scanf("%d", &key);
      if (search(root, key)) {
        printf("Valor %d encontrado na ABB", key);
      } else {
        printf("Valor %d não encontrado na ABB", key);
      }
      break;

    // Percorrendo a árvore em ordem
    case 4:
      printf("\nPercorrendo a árvore em ordem: ");
      inorder(root);
      break;

    // Percorrendo a árvore em pré-ordem
    case 5:
      printf("Percorrendo a árvore em pré-ordem: ");
      preorder(root);
      break;

    // Percorrendo a árvore em pós-ordem
    case 6:
      printf("Percorrendo a árvore em pós-ordem: ");
      postorder(root);
      break;

    // Valores mínimo e máximo
    case 7:
      printf("\nValor mínimo: %d\n", minimo(root)->key);
      printf("Valor máximo: %d", maximo(root)->key);
      break;

    case 0:
      break;

    default:
      printf("\nopcao invalida");
    }
  }

  freeTree(root);

  printf("\nObrigado por usar a arvore");

  return 0;
}