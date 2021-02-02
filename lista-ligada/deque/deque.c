#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

p_deque criar_deque() {
    p_deque deque = malloc(sizeof(Deque));
    deque->ini = NULL;
    deque->fim = NULL;
    return deque;
}

void destruir_lista_rec(p_no lista) {
    if (lista == NULL) return;
    destruir_lista_rec(lista->prox);
    free(lista);
}

void destruir_deque(p_deque deque) {
    destruir_lista_rec(deque->ini);
    free(deque);
}

void imprime_lista_rec(p_no lista) {
    if (lista == NULL) return;
    printf("Valor: %d\n", lista->dado);
    imprime_lista_rec(lista->prox);
}

void imprimir_deque(p_deque deque) {
    imprime_lista_rec(deque->ini);
}

p_deque insere_inicio(p_deque deque, int x) {
    p_no novo = malloc(sizeof(No));
    novo->dado = x;
    novo->ant = NULL;

    if(deque->ini == NULL) {
        novo->prox = NULL;
        deque->fim = novo;
        deque->ini = novo;
    } else {
        p_no anterior = deque->ini;
        anterior->ant = novo;
        novo->prox = anterior;
        deque->ini = novo;
    }
    return deque;
}

p_deque insere_fim(p_deque deque, int x) {
    p_no novo = malloc(sizeof(No));
    novo->dado = x;
    novo->prox = NULL;

    if(deque->fim == NULL) {
        novo->ant = NULL;
        deque->ini = novo;
        deque->fim = novo;
    } else {
        p_no fim_anterior = deque->fim;
        fim_anterior->prox = novo;
        novo->ant = fim_anterior;
        deque->fim = novo;
    }
    return deque;
}

int remove_inicio(p_deque deque) {
    p_no remover = deque->ini;
    int x = remover->dado;
    deque->ini = remover->prox;

    if(deque->ini == NULL) {
        deque->fim = NULL;
    } else {
        deque->ini->ant = NULL;
    }

    free(remover);
    return x;
}

int remove_fim(p_deque deque) {
    p_no remover = deque->fim;
    int x = remover->dado;
    deque->fim = remover->ant;

    if(deque->fim == NULL) {
        deque->ini = NULL;
    } else {
        deque->fim->prox = NULL;
    }

    free(remover);
    return x;
}