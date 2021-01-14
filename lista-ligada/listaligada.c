#include <stdio.h>
#include <stdlib.h>
#include "listaligada.h"

p_no criar_lista() {
    return NULL;
}

void destruir_lista_rec(p_no lista) {
    if (lista == NULL) return;
    destruir_lista_rec(lista->prox);
    free(lista);
}

void destruir_lista_iter(p_no lista) {
    p_no atual, prox;

    atual = lista;
    while (atual != NULL) {
        prox = atual->prox;
        free(atual);
        atual = prox;
    }
}

p_no adicionar_elemento(p_no lista, int x) {
    p_no novo = malloc(sizeof(No));
    novo->dado = x;
    novo->prox = lista;
    return novo;
}

p_no busca_elemento_rec(p_no lista, int x) {
    if (lista == NULL) return NULL;
    if (lista->dado == x) return lista;
    return busca_elemento_rec(lista->prox, x);
}

p_no busca_elemento_iter(p_no lista, int x) {
    for (p_no atual = lista; atual != NULL; atual = atual->prox)
        if (atual->dado == x) return atual;
    return NULL;
}

void imprime_lista_iter(p_no lista) {
    for (p_no atual = lista; atual != NULL; atual = atual->prox)
        printf("Valor: %d\n", atual->dado);
}

void imprime_lista_rec(p_no lista) {
    if (lista == NULL) return;
    printf("Valor: %d\n", lista->dado);
    imprime_lista_rec(lista->prox);
}

p_no remove_elemento(p_no lista, int x) {
    p_no anterior = NULL;
    for (p_no atual = lista; atual != NULL; atual = atual->prox) {
        if(atual->dado == x) {
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

p_no remove_ocorrencias(p_no lista, int x) {
    if (lista == NULL) return NULL;
    if (lista->dado == x) return remove_ocorrencias(lista->prox, x);
    p_no novo = malloc(sizeof(No));
    novo->dado = lista->dado;
    novo->prox = remove_ocorrencias(lista->prox, x);
    return novo;
}

p_no copiar_lista(p_no lista) {
    if (lista == NULL) return NULL;
    p_no novo = malloc(sizeof(No));
    novo->dado = lista->dado;
    novo->prox = copiar_lista(lista->prox);
    return novo;
}