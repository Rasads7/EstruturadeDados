#include <string.h>
#include <stdlib.h>
#include "tabela_hash.h"

#define TABLE_SIZE 100

char* tabela_hash[TABLE_SIZE];

int hash(char* chave) {
    int hash_value = 0;
    int m = 31;

    for (int i = 0; i < strlen(chave); i++) {
        hash_value = (hash_value * m + chave[i]) % TABLE_SIZE;
    }

    return hash_value;
}

char* hash_table_get(char* chave) {
    int index = hash(chave);

    return tabela_hash[index];
}

void hash_table_put(char* chave, char* dado) {
    int index = hash(chave);

    tabela_hash[index] = dado;
}

int hash_table_contains(char* chave) {
    int index = hash(chave);

    return tabela_hash[index] != NULL;
}

void hash_table_remove(char* chave) {
    int index = hash(chave);

    tabela_hash[index] = NULL;
}
