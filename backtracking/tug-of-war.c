#include <stdio.h>
#include <stdlib.h>

void imprime_vetor(int *vetor, int n) {
    int turma1 = 0, turma2 = 0;
    for (int i = 0; i < n; i++) {
        if (i < n / 2) turma1 += vetor[i];
        else turma2 += vetor[i];

        printf("%d ", vetor[i]);
        if (i == (n / 2) - 1) printf("\n");
    }
    printf("\nturma 1 força: %d\nturma 2 força: %d\ndiferença: %d\n\n", turma1, turma2, abs(turma1-turma2));
}

void sequenciasR(int *seq1, int *usado, int n, int *alunos, int i) {
    if (i == n) {
        imprime_vetor(seq1, n);
        return;
    }
    for (int v = 0; v < n; v++) {
        if (!usado[v]) {
            seq1[i] = alunos[v];
            usado[v] = 1;
            sequenciasR(seq1, usado, n, alunos, i + 1);
            usado[v] = 0;
        }
    }
}

void sequencias(int n, int *alunos) {
    int size = n / 2;
    int *seq1 = malloc(size * sizeof(int));
    int *usado = calloc(n + 1, sizeof(int));

    sequenciasR(seq1, usado, n, alunos, 0);
    free(seq1);
    free(usado);
}

int main() {
    int alunos[] = {1, 2, 3, 4, 5, 6};
    sequencias(6, alunos);
    return 0;
}