/* Dado um tempo t em segundos, converta para a representação
   horas-minutos-segundos.
   Exemplo: 123456s é 34h17m36s */

#include <stdio.h>

int main() {
    double segundos_entrada;
    double hora, minuto, segundo;

    printf("Entre com os segundos:\n");
    scanf("%lf", &segundos_entrada);

    hora = segundos_entrada / 3600;
    printf("hora: %d\n", (int) hora);

    minuto = (hora - (int) hora) * 60;
    printf("minuto: %d\n", (int) minuto);

    segundo = (minuto - (int) minuto) * 60;
    printf("segundo: %d\n", (int) segundo);

    return 0;
}