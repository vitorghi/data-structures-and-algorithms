#include <stdio.h>
#include "../arvore.h"

p_no torneio(int *v, int l, int r) {
    int m = (l + r) / 2;
    p_no raiz = criar_arvore(v[m], NULL, NULL);
    if (l < r) {
        raiz->esq = torneio(v, l, m);
        raiz->dir = torneio(v, m+1, r);
        raiz->dado = (raiz->esq->dado > raiz->dir->dado) ? raiz->esq->dado : raiz->dir->dado;
   }
    return raiz;
}

int main() {
    int participantes[] = {5, 1, 7, 4, 3, 2, 6, 8};

    p_no resultado = torneio(participantes, 0, 7);
    imprime_pre_ordem(resultado);
    printf("\n");
    percurso_em_largura(resultado);
    printf("\n");

    return 0;
}
