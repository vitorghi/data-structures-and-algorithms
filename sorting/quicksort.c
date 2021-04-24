#include <stdio.h>
#include <stdlib.h>

void troca(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int *v, int l, int r) {
    int i, pivo = v[l], posicao_pivo = r + 1;
    for(i = r; i >= l; i--)
        if (v[i] >= pivo) {
            posicao_pivo--;
            troca(&v[i], &v[posicao_pivo]);
        }
    return posicao_pivo;
}

void quicksort(int *v, int l, int r) {
    if (l < r) {
        int i = partition(v, l, r);
        quicksort(v, l, i - 1);
        quicksort(v, i + 1, r);
    }
}

int main() {
    int v[] = {7,9,11,13,1,5,6};
    int n = 7;
    //int v[100000];
    //int n = 100000;
    //for (int i = 0; i < n; i++)
    //    v[i] = rand();

    quicksort(v, 0, n);

    for (int i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");

    return 0;
}