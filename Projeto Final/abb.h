#ifndef ABB_H_INCLUDED
#define ABB_H_INCLUDED

typedef struct TreeNode {
  int key;                // Valor do nó
  struct TreeNode *left;  // Ponteiro para o filho esquerdo
  struct TreeNode *right; // Ponteiro para o filho direito
} Node;

Node *insert(Node *root, int value);

Node *removeNode(Node *root, int value);

int search(Node *root, int value);

void inorder(Node *root);

void preorder(Node *root);

void postorder(Node *root);

Node *minimo(Node *root);

Node *maximo(Node *root);

void freeTree(Node *root);

#endif