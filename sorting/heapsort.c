#include <stdio.h>
#include <stdlib.h>
#include "../heap/priority-queue.h"

#define F_ESQ(i) ((2 * i) + 1)
#define F_DIR(i) ((2 * i) + 2)

// Complexidade tempo: O(n lg n)
// Mas ainda perde espaço e tempo para copiar e transformar vetor para heap.
void fpsort(Item *v, int n) {
    p_fp fprio = criar_fila_prioridade(n);
    for (int i = 0; i < n; i++)
        insere(fprio, v[i]);
    for (int i = n - 1; i >= 0; i--)
        v[i] = extrai_maximo(fprio);
    destroi(fprio);
}

// Melhorando...
void troca_int(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void desce_no_heap_2(int *heap, int n, int k) {
    int maior_filho;
    if (F_ESQ(k) < n) {
        maior_filho = F_ESQ(k);
        if (F_DIR(k) < n && heap[F_ESQ(k)] < heap[F_DIR(k)])
            maior_filho = F_DIR(k);

        if (heap[k] < heap[maior_filho]) {
            troca_int(&heap[k], &heap[maior_filho]);
            desce_no_heap_2(heap, n, maior_filho);
        }
    }
}

void heapsort(int *v, int n) {
    for (int k = n/2; k >= 0; k--) /* transforma em heap */
        desce_no_heap_2(v, n, k);
    while (n > 1) { /* extrai o máximo */
        troca_int(&v[0], &v[n - 1]);
        n--;
        desce_no_heap_2(v, n, 0);
    }
}

int main() {
    int v[100000];
    int n = 100000;
    for (int i = 0; i < n; i++)
        v[i] = rand();

    heapsort(v, n);

    //for (int i = 0; i < n; i++)
    //    printf("%d ", v[i]);
    //printf("\n");

    return 0;
}