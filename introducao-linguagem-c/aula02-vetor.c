#include <stdio.h>

void le_vetor(int vetor[], int n);
void calcula_produto(int vetor1[], int vetor2[], int produto[], int n);
void imprime_resultado(int vetor[], int n);

int main() {
    int tamanho = 100;
    int vetor1[tamanho], vetor2[tamanho], produto[tamanho];

    le_vetor(vetor1, tamanho);
    le_vetor(vetor2, tamanho);

    calcula_produto(vetor1, vetor2, produto, tamanho);
    imprime_resultado(produto, tamanho);

    return 0;
}

void le_vetor(int vetor[], int n) {
    printf("Lendo vetor\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &vetor[i]);
}

void calcula_produto(int vetor1[], int vetor2[], int produto[], int n) {
    printf("Calculando produto\n");
    for (int i = 0; i < n; i++)
        produto[i] = vetor1[i] * vetor2[i];
}

void imprime_resultado(int vetor[], int n) {
    printf("Imprimindo resultado\n");
    for (int i = 0; i < n; i++)
        printf("%d\n", vetor[i]);
}
