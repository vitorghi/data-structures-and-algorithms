/* Ponteiros
    Um ponteiro é uma variável que armazena um endereço
        • para um tipo específico de informação
            – int, char, double, structs declaradas, etc
*/
#include <stdio.h>
#include <stdlib.h>

int main() {

    int *endereco;
    int variavel = 90;
    endereco = &variavel;
    printf("Variavel: %d\n", variavel);
    printf("Variavel: %d\n", *endereco);
    printf("Endereço: %p\n", endereco);
    printf("Endereço: %p\n", &variavel);

    return 0;
}

double * aloca_dinamicamente(int n) {
    double *v = malloc(n * sizeof(double));
    if (v == NULL)
        exit(1);

    for (int i = 0; i < n; i++)
        v[i] = 0.0;

    return v;
}

void imprime(double *v, int n) {
    for (int i = 0; i < n; i++)
        printf("pos %d: %f", i, v[i]);
}