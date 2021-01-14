#include <stdio.h>
#include "listaligada.h"

int main() {
    p_no lista = criar_lista();

    lista = adicionar_elemento(lista, 1);
    lista = adicionar_elemento(lista, 2);
    lista = adicionar_elemento(lista, 3);
    lista = adicionar_elemento(lista, 4);
    lista = adicionar_elemento(lista, 4);

    lista = remove_ocorrencias(lista, 4);

    imprime_lista_rec(lista);
    destruir_lista_rec(lista);

    return 0;
}