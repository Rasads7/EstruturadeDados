#include <stdio.h>
#include <stdlib.h>
#include "tabela_hash.h"

int main() {
  hash_table_put("chave1", "1");
  hash_table_put("chave2", "2");
  hash_table_put("chave3", "3");

  printf("Contém chave 1? %d\n", hash_table_contains("chave1"));
  printf("Contém chave 2? %d\n", hash_table_contains("chave2"));
  printf("Contém chave 3? %d\n", hash_table_contains("chave3"));
  printf("Contém chave 4? %d\n", hash_table_contains("chave4"));

  printf("Valor da chave 1: %s\n", hash_table_get("chave1"));
  printf("Valor da chave 2: %s\n", hash_table_get("chave2"));
  printf("Valor da chave 3: %s\n", hash_table_get("chave3"));

  hash_table_remove("chave2");

  printf("Contém chave 2? %d\n", hash_table_contains("chave2"));

  return 0;
}