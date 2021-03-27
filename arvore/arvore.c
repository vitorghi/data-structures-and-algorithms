#include <stdlib.h>
#include <stdio.h>
#include "arvore.h"
#include "../pilha/pilha.h"
#include "../fila/fila.h"

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

// Percurso em largura
void percurso_em_largura(p_no raiz) {
    p_fila fila = criar_fila();
    enfileirar(fila, raiz);
    while(!eh_vazia(fila)) {
        raiz = desenfileirar(fila);
        if (raiz != NULL) {
            enfileirar(fila, raiz->dir);
            enfileirar(fila, raiz->esq);
            printf("%d", dado);
        }
    }
    destruir_fila(fila);
}

void conta_folhas(p_no raiz, int count) {
    if (raiz == NULL) return;
    if (raiz->esq == NULL && raiz->dir == NULL) count++;
    conta_folhas(raiz->esq, count);
    conta_folhas(raiz->dir, count);
}

int arvore_eh_igual(p_no primeira, p_no segunda) {
    p_fila fila = criar_fila();
    int eh_igual = 1;

    enfileirar(fila, primeira);
    enfileirar(fila, segunda);

    while(!eh_vazia(fila)) {
        primeira = desenfileirar(fila);
        segunda = desenfileirar(fila);
        if (primeira == NULL && segunda == NULL) break;
        else if ((primeira == NULL && segunda != NULL) || (primeira != NULL && segunda == NULL)) {
            eh_igual = 0;
            break;
        }
        else if (primeira->dado == segunda->dado) {
            enfileirar(fila, primeira->dir);
            enfileirar(fila, segunda->dir);
            enfileirar(fila, primeira->esq);
            enfileirar(fila, segunda->esq);
        } else {
            eh_igual = 0;
            break;
        }
    }

    destruir_fila(fila);
    return eh_igual;
}