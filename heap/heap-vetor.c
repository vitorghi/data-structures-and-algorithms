#include <heap.h>
#include <stdio.h>
#include <stdlib.h>

void troca(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

p_fp criar_fila_prioridade(int tamanho) {
    p_fp fprio = malloc(sizeof(FP));
    fprio->v = malloc(tamanho * sizeof(Item));
    fprio-> n = 0;
    fprio->tamanho = tamanho;
    return fprio;
}

// O(1)
void insere(p_fp fprio, Item item) {
    fprio->v[fprio->n] = item;
    fprio->n++;
}

// O(n)
Item extrai_maximo(p_fp fprio) {
    int j, max = 0;
    for (j = 1; j < fprio->n; j++)
        if (fprio->v[max].chave < fprio->v[j].chave)
            max = j;
    troca(&(fprio->v[max]), &(fprio->v[fprio->n - 1]));
    fprio->n--;
    return fprio->v[fprio->n];
}

int vazia(p_fp fprio) {
    return fprio->n == 0;
}

int cheia(p_fp fprio) {
    return fprio->n == fprio->tamanho;
}