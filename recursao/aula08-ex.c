/*
Crie um algoritmo que, dado n e C, imprime todas as sequências
de números não-negativos x1, x2, . . . , xn tal que
        x1 + x2 + ··· + xn = C
a) Modifique o seu algoritmo para considerar apenas sequências
sem repetições
b) Modifique o seu algoritmo para imprimir apenas sequências
com x1 ≤ x2 ≤ ··· ≤ xn
*/
#include <stdio.h>
#include <stdlib.h>

void imprime_vetor(int *vetor, int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", vetor[i]);
    printf("\n");
}

int pode_inserir(int *vetor, int v, int n, int C) {
    int soma = 0;
    for (int i = 0; i < n; i++) {
        if (v == vetor[i])
            return 0;
        soma += vetor[i];
    }
    soma += v;
    if (soma > C)
        return 0;
    return 1;
}

int soma_correta(int *seq, int n, int C) {
    int soma = 0;
    for (int i = 0; i < n; i++)
        soma += seq[i];
    if (soma != C)
        return 0;
    return 1;
}

void sequenciasR(int *seq, int C, int n, int i){
    if (i == n) {
        if(soma_correta(seq, n, C))
            imprime_vetor(seq, n);
        return;
    }
    for (int v = 0; v <= C; v++) {
        if (pode_inserir(seq, v, i, C)) {
            seq[i] = v;
            sequenciasR(seq, C, n, i + 1);
        }
    }
}

void sequencias(int n, int C) {
    int *seq = malloc(n * sizeof(int));
    sequenciasR(seq, C, n, 0);
    free(seq);
}

int main() {
    sequencias(3, 3);
    return 0;
}