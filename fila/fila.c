#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

p_fila criar_fila() {
    p_fila f = malloc(sizeof(Fila));
    f->ini = NULL;
    f->fim = NULL;
    return f;
}

void destruir_fila(p_fila f) {
    destruir_lista_rec(f->ini);
    free(f);
}

void imprimir_fila(p_fila f) {
    imprime_lista_rec(f->ini);
}

void enfileirar(p_fila f, int x) {
    p_no novo = malloc(sizeof(No));
    novo->dado = x;
    novo->prox = NULL;
    if (f->ini == NULL) {
        f->ini = novo;
    } else {
        f->fim->prox = novo;
    }
    f->fim = novo;
}

int desenfileirar(p_fila f) {
    //if (f->ini == NULL) return ERROR;
    p_no primeiro = f->ini;
    int dado = primeiro->dado;
    f->ini = f->ini->prox;
    if(f->ini == NULL) {
        f->fim = NULL;
    }
    free(primeiro);
    return dado;
}