#include <stdio.h>
#include <stdlib.h>

void troca(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void bubble_sort(int *v, int n) {
    for (int i = 0; i < n; i++)
        for (int j = n - 1; j > i; j--)
            if (v[j] < v[j-1])
                troca(&v[j-1], &v[j]);
}

int main() {
    int v[100000];
    int n = 100000;
    for (int i = 0; i < n; i++)
        v[i] = rand();
    bubble_sort(v, n);

    //for (int i = 0; i < n; i++)
    //    printf("%d ", v[i]);

    return 0;
}