#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"

p_hash criar_hash() {
    return malloc(sizeof(Hash));
}

void destruir_hash(p_hash t) {

}

int hash(char *chave) {
    return 0;
}

void inserir(p_hash t, char *chave, int dado) {

}

void remover(p_hash t, char *chave) {

}

p_no buscar(p_hash t, char *chave) {
    int n = hash(chave);
    return t->vetor[n];
}
