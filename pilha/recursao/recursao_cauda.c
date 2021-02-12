#include <stdio.h>
#include "../pilha.h"

int loop(p_no atual, p_no anterior) {
    if (atual == NULL)
        return 1;
    if (anterior && anterior->dado > atual->dado)
        return 0;
    return loop(atual->prox, atual);
}

int verifica_lista_crescente(p_no lista) {
    p_no anterior = NULL;
    return loop(lista, anterior);
}

int remove_recursao_cauda(p_no lista) {
    p_no atual = lista;
    p_no anterior = NULL;
    while (atual != NULL) {
        if (anterior && anterior->dado > atual->dado)
            return 0;
        anterior = atual;
        atual = atual->prox;
    }
    return 1;
}