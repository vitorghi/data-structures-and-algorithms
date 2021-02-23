#include <stdlib.h>
#include <stdio.h>
#include "arvore.h"
#include "../pilha/pilha.h"

p_no criar_arvore(int x, p_no esq, p_no dir) {
    p_no raiz = malloc(sizeof(No));
    raiz->dado = x;
    raiz->esq = esq;
    raiz->dir = dir;
    return raiz;
}

p_no procurar_no(p_no raiz, int x) {
    if (raiz == NULL || raiz->dado == x)
        return raiz;
    p_no esq =  procurar_no(raiz->esq, x);
    if (esq != NULL) return esq;
    return procurar_no(raiz->dir, x);
}

int numero_nos(p_no raiz) {
    if (raiz == NULL)
        return 0;
    return numero_nos(raiz->esq) + numero_nos(raiz->dir) + 1;
}

int altura(p_no raiz) {
    if (raiz == NULL)
        return 0;
    int h_esq = altura(raiz->esq);
    int h_dir = altura(raiz->dir);
    return 1 + (h_esq > h_dir ? h_esq : h_dir);
}

/*
    Percursos em profundidade (Depth-first)
      - relacionado com backtracking.

    Como eliminar a recursão?
      - usando uma outra pilha para simular a recursão.
*/
void imprime_pre_ordem(p_no raiz) {
    if (raiz == NULL) return;
    printf("%d", raiz->dado);
    imprime_pre_ordem(raiz->esq);
    imprime_pre_ordem(raiz->dir);
}

void imprime_pos_ordem(p_no raiz) {
    if (raiz == NULL) return;
    imprime_pos_ordem(raiz->esq);
    imprime_pos_ordem(raiz->dir);
    printf("%d", raiz->dado);
}

void imprime_in_ordem(p_no raiz) {
    if (raiz == NULL) return;
    imprime_in_ordem(raiz->esq);
    printf("%d", raiz->dado);
    imprime_in_ordem(raiz->dir);
}

void imprime_pre_ordem_iterativo(p_no raiz) {
    p_pilha pilha = criar_pilha();
    empilhar(pilha, raiz);
    while(!eh_vazia(pilha)) {
        raiz = desempilhar(pilha);
        if (raiz != NULL) {
            empilhar(pilha, raiz->dir);
            empilhar(pilha, raiz->esq);
            printf("%d", dado);
        }
    }
    destruir_pilha(pilha);
}