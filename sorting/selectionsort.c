#include <stdio.h>

void troca(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Extrair máximo leva tempo O(k), mas podemos substituir por uma heap, que leva O(lg K)
int extrai_maximo(int *v, int i) {
    int max = i - 1;
    for (int j = i - 2; j >= 0; j--)
        if (v[j] > v[max])
            max = j;
    return max;
}

// Algoritmo leva O(n²), mas com a ideia acima de extrair maximo com heap, será melhorado.
void selectionsort(int *v, int n) {
    int max;
    for (int i = n - 1; i > 0; i--) {
        max = extrai_maximo(v, i);
        troca(&v[i], &v[max]);
    }
}

int main() {
    int v[] = {7,9,11,13,1,5,6};
    int n = 7;
    selectionsort(v, n);

    for (int i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");

    return 0;
}