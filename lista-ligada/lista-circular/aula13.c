#include <stdio.h>
#include "listacircular.h"

int main() {
    p_no lista_circular = criar_lista_circular();

    lista_circular = inserir_circular(lista_circular, 0);
    lista_circular = inserir_circular(lista_circular, 1);
    lista_circular = inserir_circular(lista_circular, 2);
    lista_circular = inserir_circular(lista_circular, 3);
    lista_circular = inserir_circular(lista_circular, 4);
    lista_circular = inserir_circular(lista_circular, 5);

    imprimir_circular(lista_circular);
}