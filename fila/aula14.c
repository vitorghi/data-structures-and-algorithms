#include <stdio.h>
#include "fila.h"

int main() {
    p_fila fila = criar_fila();
    enfileirar(fila, 1);
    enfileirar(fila, 2);
    enfileirar(fila, 3);
    enfileirar(fila, 4);
    enfileirar(fila, 5);

    imprimir_fila(fila);
    int resultado = desenfileirar(fila);
    printf("\n desenfileirado: %d\n", resultado);
    imprimir_fila(fila);

    destruir_fila(fila);

    return 0;
}