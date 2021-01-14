#include <stdio.h>
#include <stdlib.h>

void imprime_vetor(int *vetor, int n, int diff){
    for (int i = 0; i < n; i++)
        printf("%d ", vetor[i]);
    printf("\n");
}

void sequenciasR(int *seq1, int *usado, int n, int *alunos, int i, int diff) {
    // melhorar o vetor usado, considerar um id, invés da força que pode ser repetida
    if (i == n / 2) {
        imprime_vetor(seq1, n / 2, diff);
        return;
    }
    for (int v = 0; v < n; v++) {
        if (!usado[v]) {
            seq1[i] = alunos[v];
            usado[v] = 1;
            sequenciasR(seq1, usado, n, alunos, i + 1, diff);
            usado[v] = 0;
        }
    }
}

void sequencias(int n, int *alunos) {
    int size = n / 2;
    int *seq1 = malloc(size * sizeof(int));
    int *usado = calloc(n + 1, sizeof(int));

    sequenciasR(seq1, usado, n, alunos, 0, __INT_MAX__);
    //int diff = sequenciasR(seq1, usado, n, alunos, 0, __INT_MAX__);
    //printf("Menor diferença entre turmas: %d", diff);
    free(seq1);
}

int main() {
    int alunos[] = {1, 2, 3, 4};
    sequencias(4, alunos);
    return 0;
}