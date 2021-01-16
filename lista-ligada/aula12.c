#include <stdio.h>
#include "listaligada.h"

int main() {
    p_no lista = criar_lista();

    lista = adicionar_elemento(lista, 1);
    lista = adicionar_elemento(lista, 2);
    lista = adicionar_elemento(lista, 3);
    lista = adicionar_elemento(lista, 4);
    lista = adicionar_elemento(lista, 7);

    printf("imprimindo lista:\n");
    imprime_lista_rec(lista);


    //lista = remove_ocorrencias(lista, 4);
    //p_no nova_lista = copiar_lista_iter(lista);

    p_no invertida = inverter_lista_iter(lista);
    printf("imprimindo lista invertida:\n");
    imprime_lista_rec(invertida);

    destruir_lista_rec(lista);
    //destruir_lista_rec(invertida);

    return 0;
}