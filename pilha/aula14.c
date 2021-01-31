#include <stdio.h>
#include "pilha.h"

int main() {
    p_pilha pilha = criar_pilha();
    empilhar(pilha, 1);
    empilhar(pilha, 2);
    empilhar(pilha, 3);
    empilhar(pilha, 4);
    empilhar(pilha, 5);

    imprimir_pilha(pilha);

    int topo = desempilhar(pilha);
    printf("Desempilhado: %d\n", topo);
    imprimir_pilha(pilha);
    destruir_pilha(pilha);

    return 0;
}