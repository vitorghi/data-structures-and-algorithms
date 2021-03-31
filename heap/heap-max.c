#include <heap.h>
#include <stdio.h>
#include <stdlib.h>

#define PAI(i) ((i - 1) / 2)
#define FILHO_ESQ(i) ((2 * i) + 1)
#define FILHO_DIR(i) ((2 * i) + 2)

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

void sobe_no_heap(p_fp fprio, int k) {
    if (k > 0 && fprio->v[PAI(k)].chave < fprio->v[k].chave) {
        troca(&fprio->v[k], &fprio->v[PAI(k)]);
        sobe_no_heap(fprio, PAI(k));
    }
}

// O(lg n)
void insere(p_fp fprio, Item item) {
    fprio->v[fprio->n] = item;
    fprio->n++;
    sobe_no_heap(fprio, fprio->n - 1);
}

void desce_no_heap(p_fp fprio, int k) {
    int maior_filho;
    if (FILHO_ESQ(k) < fprio->n) {
        maior_filho = FILHO_ESQ(k);
        if (FILHO_DIR(k) < fprio->n &&
            fprio->v[FILHO_ESQ(k)].chave < fprio->v[FILHO_DIR(k)].chave)
                maior_filho = FILHO_DIR(k);
        if (fprio->v[k].chave < fprio->v[maior_filho].chave) {
            troca(&fprio->v[k], &fprio->v[maior_filho]);
            desce_no_heap(fprio, maior_filho);
        }
    }
}

// O(lg n)
Item extrai_maximo(p_fp fprio) {
    Item item = fprio->v[0];
    fprio->v[0] = fprio->v[fprio->n - 1];
    fprio->n--;
    desce_no_heap(fprio, 0);
    return item;
}
