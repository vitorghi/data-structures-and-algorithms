#include <stdio.h>
#include <stdlib.h>
#include "listacircular.h"

p_no criar_lista_circular() {
    return NULL;
}

// O(1)
p_no inserir_circular(p_no lista, int x) {
    p_no novo = malloc(sizeof(No));
    novo->dado = x;

    // checagem pode ser removida por uma impl de lista com cabeça.
    if (lista == NULL) {
        novo->prox = novo;
        lista = novo;
    } else {
        novo->prox = lista->prox;
        lista->prox = novo;
    }
    return lista;
}

// O(n)
p_no remover_circular(p_no lista, p_no no) {
    p_no ant;
    if (no->prox == no) { // único elemento
        free(no);
        return NULL;
    }
    for (ant = no->prox; ant->prox != no; ant = ant->prox);
    ant->prox = no->prox;
    if (lista == no) lista = ant;
    free(no);
    return lista;
}

void imprimir_circular(p_no lista) {
    if (lista == NULL) return;
    p_no p = lista->prox;
    do {
        printf("%d\n", p->dado);
        p = p->prox;
    } while(p != lista->prox);
}