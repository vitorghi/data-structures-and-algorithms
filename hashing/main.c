#include <stdio.h>
#include "hashtable.h"

int main() {
    p_hash t = criar_hash();
    inserir(t, "bala", 3);
    p_no r = buscar(t, "bala");
    printf("Busca na hash table: \n");
    printf("Dado encontrado %d com a chave %s\n", r->dado, r->chave);
    destruir_hash(t);
    return 0;
}