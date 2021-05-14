#include <stdio.h>
#include "red-black-tree.h"

void imprime_pre_ordem(p_no raiz) {
    if (raiz == NULL) return;
    printf("%d ", raiz->chave);
    imprime_pre_ordem(raiz->esq);
    imprime_pre_ordem(raiz->dir);
}

void imprime_in_ordem(p_no raiz) {
    if (raiz == NULL) return;
    imprime_in_ordem(raiz->esq);
    printf("%d ", raiz->chave);
    imprime_in_ordem(raiz->dir);
}

int main() {
    p_no no1    = inserir(NULL, 1);
    p_no no2    = inserir(no1, 2);
    p_no no3    = inserir(no2, 3);
    p_no arvore = inserir(no3, 4);

    printf("pre-order\n");
    imprime_pre_ordem(arvore);
    printf("\n");

    printf("in-order\n");
    imprime_in_ordem(arvore);
    printf("\n");

    return 0;
}