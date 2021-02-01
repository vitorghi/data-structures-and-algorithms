#include <stdio.h>
#include <stdlib.h>
#include "deque.h"~

p_deque criar_deque() {
    p_deque deque = malloc(sizeof(Deque));
    deque->ini = NULL;
    deque->fim = NULL;
    return deque;
}

void destruir_deque(p_deque deque) {
    destruir_lista_rec(deque->ini);
    free(deque);
}

void imprimir_deque(p_deque deque) {
    imprime_lista_rec(deque->ini);
}

p_deque insere_inicio(p_deque deque, int x) {
    p_no novo = malloc(sizeof(No));
    novo->dado = x;
    if(deque->ini == NULL) {
        deque->ini = novo;
        deque->fim = novo;
    } else {
        p_no anterior = deque->ini;
        novo->prox = anterior;
        deque->ini = novo;
    }
    return deque;
}

p_deque insere_fim(p_deque deque, int x) {
    p_no novo = malloc(sizeof(No));
    novo->dado = x;
    if(deque->fim == NULL) {
        deque->ini = novo;
        deque->fim = novo;
    } else {
        p_no fim_anterior = deque->fim;
        fim_anterior->prox = novo;
        deque->fim = novo;
    }
    return deque;
}

int remove_inicio(p_deque deque) {

}

int remove_fim(p_deque deque) {

}