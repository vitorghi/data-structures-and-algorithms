/*
    Implementação eficiente de uma ADT de priority queue usando heap.
    Operações levam O(lg n).

    Uma Binary (Max) Heap é uma árvore binária completa que mantém a propriedade de Max Heap.
        - A raiz precisa ter uma chave de maior valor(prioridade) que seus filhos.
        - E para ser uma árvore binária completa, a altura precisa ser de (lg n) e no último nível,
          as folhas precisam estar o máximo a esquerda possível.

    E, devido às propriedades acima, podemos representar uma árvore binária completa com vetor.
    Exemplo:
                    v[0]
                v[1]    v[2]
            v[3]  v[4] v[5]  v[6]
          v[7]v[8]

    Com isso, conseguimos saber os índices dos filhos e do pai de cada nó.
*/

#include <priority-queue.h>
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
    troca(&fprio->v[0], &fprio->v[fprio->n - 1]);
    fprio->n--;
    desce_no_heap(fprio, 0);
    return item;
}

// O(lg n) mas precisamos conhecer a posição do item
// podemos associar o item ao "id", usando hash table
void muda_prioridade(p_fp fprio, int k, int valor) {
    int chave_antiga = fprio->v[k].chave;
    fprio->v[k].chave = valor;
    chave_antiga > valor ? desce_no_heap(fprio, k) : sobe_no_heap(fprio, k);
}
