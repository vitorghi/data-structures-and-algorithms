#include <stdio.h>

/*
    Uso da divisão e conquista no algoritmo, a função merge(intercalação) leva tempo O(n)
    e ela é chamada (lg n) vezes, altura da árvore recursiva. Portanto, mesmo no pior caso,
    o merge sort tem uma complexidade de tempo O(n lg n), linearítmico.

    No entanto, visto que a solução usa um vetor auxiliar, a complexidade de espaço é O(n)
*/

#define MAX 100

void merge(int *v, int l, int m, int r) {
    int aux[MAX];
    int i = l, j = m+1, k = 0;
    // intercala
    while (i <= m && j <= r)
        if (v[i] <= v[j])
            aux[k++] = v[i++];
        else
            aux[k++] = v[j++];
    // copia o resto do vetor que não terminou
    while (i <= m)
        aux[k++] = v[i++];
    while (j <= r)
        aux[k++] = v[j++];
    // copia de aux para o vetor inicial
    for (i = l, k = 0; i <= r; i++, k++)
        v[i] = aux[k];
}

void mergesort(int *v, int l, int r) {
    int m = (l + r) / 2;
    if (l < r) {
        // divisao
        mergesort(v, l, m);
        mergesort(v, m + 1, r);
        // conquista
        merge(v, l, m, r);
    }
}

int main() {
    int v[] = {4,8,2,7,6,3,5,1,9,10};
    int n = 9;
    mergesort(v, 0, n);

    for (int i = 0; i <= n; i++)
        printf("%d ", v[i]);
    printf("\n");

    return 0;
}