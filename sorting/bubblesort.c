#include <stdio.h>

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
    int v[] = {7,9,11,13,1,5,6};
    int n = 7;
    bubble_sort(v, n);

    for (int i = 0; i < n; i++)
        printf("%d ", v[i]);

    return 0;
}