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

    p_no nova_lista = copiar_lista_rec(lista);
    printf("imprimindo lista copiada recursivamente:\n");
    imprime_lista_rec(nova_lista);

    p_no invertida = inverter_lista_rec(nova_lista);
    printf("imprimindo lista invertida recursivamente:\n");
    imprime_lista_rec(invertida);

    p_no concatenada = concatenar_listas_rec(lista, invertida);
    printf("imprimindo lista concatenada recursivamente:\n");
    imprime_lista_rec(concatenada);

    destruir_lista_rec(concatenada);
    return 0;
}