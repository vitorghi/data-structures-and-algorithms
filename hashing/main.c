#include <stdio.h>
#include "hashtable.h"

int main() {
    p_hash t = criar_hash();
    inserir(t, "bala", 3);
    inserir(t, "teste", 5);

    p_no r = buscar(t, "bala");
    printf("Busca na hash table: \n");
    printf("Dado encontrado %d com a chave %s\n", r->dado, r->chave);

    remover(t, "teste");
    p_no r2 = buscar(t, "teste");
    printf("Busca na hash table: \n");
    printf("Dado encontrado %d com a chave %s\n", r2->dado, r2->chave);

    destruir_hash(t);
    return 0;
}