#include <stdio.h>
#include <math.h>

#define ERRO 10e-12

double sqroot(double x) {
    double estimativa = x, anterior;

     do {
        anterior = estimativa;
        estimativa = (estimativa + x / estimativa) / 2;
     } while (fabs(anterior - estimativa) > ERRO);

    return estimativa;
}

int main() {
    double x;

    printf("Insira numero para calcular a raiz quadrada\n");
    scanf("%lf", &x);

    printf("A raiz é: %f\n", sqroot(x));
    return 0;
}