#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"

p_hash criar_hash() {
    return malloc(sizeof(Hash));
}

void destruir_hash(p_hash t) {
    for (int i = 0; i < MAX; i++) {
        destruir_lista(t->vetor[i]);
    }
    free(t);
}

int hash(char *chave) {
    int i, n = 0;
    for (i = 0; i < strlen(chave); i++)
        n = (256 * n + chave[i]) % MAX;
    return n;
}

void inserir(p_hash t, char *chave, int dado) {
    int n = hash(chave);
    t->vetor[n] = inserir_lista(t->vetor[n], chave, dado);
}

void remover(p_hash t, char *chave) {
    int n = hash(chave);
    t->vetor[n] = remover_lista(t->vetor[n], chave);
}

p_no buscar(p_hash t, char *chave) {
    int n = hash(chave);
    return busca_elemento_lista(t->vetor[n], chave);
}

// Operações lista ligada
p_no inserir_lista(p_no lista, char *chave, int x) {
    p_no no = malloc(sizeof(No));
    no->chave = chave;
    no->dado = x;
    no->prox = lista;
    return no;
}

p_no remover_lista(p_no lista, char *chave) {
    p_no anterior = NULL;
    for (p_no atual = lista; atual != NULL; atual = atual->prox) {
        if (atual->chave == chave) {
            if (anterior == NULL) {
                return atual->prox;
            } else {
                anterior->prox = atual->prox;
                return lista;
            }
        }
        anterior = atual;
    }
    return lista;
}

p_no busca_elemento_lista(p_no lista, char *chave) {
    if (lista == NULL || lista->chave == chave) {
        return lista;
    }
    return busca_elemento_lista(lista->prox, chave);
}

void destruir_lista(p_no lista) {
    if (lista == NULL) return;
    destruir_lista(lista->prox);
    free(lista);
}
