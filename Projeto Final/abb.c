#include "abb.h"
#include <stdio.h>
#include <stdlib.h>

Node *createNode(int value) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->key = value;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

Node *insert(Node *root, int value) {
  if (root == NULL) {
    return createNode(value);
  }

  if (value < root->key) {
    root->left = insert(root->left, value);
  } else if (value > root->key) {
    root->right = insert(root->right, value);
  }

  return root;
}

Node *removeNode(Node *root, int value) {
  if (root == NULL) {
    return root;
  }

  if (value < root->key) {
    root->left = removeNode(root->left, value);
  } else if (value > root->key) {
    root->right = removeNode(root->right, value);
  } else {
    if (root->left == NULL) {
      Node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      Node *temp = root->left;
      free(root);
      return temp;
    }

    Node *successor = minimo(root->right);
    root->key = successor->key;
    root->right = removeNode(root->right, successor->key);
  }

  return root;
}

int search(Node *root, int value) {
  if (root == NULL) {
    return 0;
  }

  if (value < root->key) {
    return search(root->left, value);
  } else if (value > root->key) {
    return search(root->right, value);
  }

  return 1;
}

void inorder(Node *root) {
  if (root != NULL) {
    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
  }
}

void preorder(Node *root) {
  if (root != NULL) {
    printf("%d ", root->key);
    preorder(root->left);
    preorder(root->right);
  }
}

void postorder(struct TreeNode *root) {
  if (root != NULL) {
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->key);
  }
}

Node *minimo(struct TreeNode *root) {
  if (root == NULL) {
    return NULL;
  }

  while (root->left != NULL) {
    root = root->left;
  }

  return root;
}

Node *maximo(struct TreeNode *root) {
  if (root == NULL) {
    return NULL;
  }

  while (root->right != NULL) {
    root = root->right;
  }

  return root;
}

void freeTree(struct TreeNode *root) {
  if (root != NULL) {
    freeTree(root->left);
    freeTree(root->right);
    free(root);
  }
}