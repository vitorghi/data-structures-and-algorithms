#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

p_pilha criar_pilha() {
    p_pilha p = malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

void destruir_pilha(p_pilha p) {
    destruir_lista_rec(p->topo);
    free(p);
}

void imprimir_pilha(p_pilha p) {
    imprime_lista_rec(p->topo);
}

void empilhar(p_pilha p, int x) {
    p_no novo = malloc(sizeof(No));
    novo->dado = x;
    novo->prox = p->topo;
    p->topo = novo;
}

int desempilhar(p_pilha p) {
    p_no desempilhado = p->topo;
    int dado = desempilhado->dado;
    p->topo = p->topo->prox;
    free(desempilhado);
    return dado;
}