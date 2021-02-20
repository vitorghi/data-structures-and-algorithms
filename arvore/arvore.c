#include <stdlib.h>
#include <stdio.h>
#include "arvore.h"

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