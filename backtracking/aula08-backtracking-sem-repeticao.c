#include <stdio.h>
#include <stdlib.h>

void imprime_vetor(int *vetor, int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", vetor[i]);
    printf("\n");
}

void sequenciasR(int *seq, int *usado, int n, int k, int i) {
    int v;
    if (i == k) {
        imprime_vetor(seq, k);
        return;
    }
    for (v = 1; v <= n; v++) {
        if (!usado[v]) {
            seq[i] = v;
            usado[v] = 1;
            sequenciasR(seq, usado, n, k, i + 1);
            usado[v] = 0;
        }
    }
}

void sequencias(int n, int k) {
    int *seq = malloc(k * sizeof(int));
    int *usado = calloc(n + 1, sizeof(int));
    sequenciasR(seq, usado, n, k, 0);
    free(seq);
    free(usado);
}

int main() {
    sequencias(3, 3);
    return 0;
}