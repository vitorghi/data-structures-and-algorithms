#include <stdio.h>

void troca(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void selectionsort(int *v, int n) {
    int min;
    for (int i = 0; i < n - 1; i++) {
        min = i;
        for (int j = i+1; j < n; j++)
            if (v[j] < v[min])
                min = j;
        troca(&v[i], &v[min]);
    }
}

int main() {
    int v[] = {7,9,11,13,1,5,6};
    int n = 7;
    selectionsort(v, n);

    for (int i = 0; i < n; i++)
        printf("%d ", v[i]);

    return 0;
}