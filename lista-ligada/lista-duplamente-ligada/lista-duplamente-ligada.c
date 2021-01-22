#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *prox;
    struct No *ant;
} No;

typedef struct No * p_no;

p_no criar_lista();
p_no inserir(p_no lista, int x);
void imprimir(p_no lista);
void destruir(p_no lista);

int main() {
    p_no lista = criar_lista();
    lista = inserir(lista, 1);
    lista = inserir(lista, 2);
    lista = inserir(lista, 3);
    lista = inserir(lista, 4);
    lista = inserir(lista, 5);

    imprimir(lista);
    destruir(lista);
}

p_no criar_lista() {
    return NULL;
}

p_no inserir(p_no lista, int x) {
    p_no novo = malloc(sizeof(No));
    novo->dado = x;
    if (lista != NULL) {
        novo->prox = lista->prox;
        novo->ant = lista;
        lista->prox = novo;
    } else {
        novo->prox = NULL;
        novo->ant = NULL;
        return novo;
    }

    return lista;
}

void imprimir(p_no lista) {
    for (p_no atual = lista; atual != NULL; atual = atual->prox)
        printf("%d\n", atual->dado);
}

void destruir(p_no lista) {
    if (lista == NULL) return;
    destruir(lista->prox);
    free(lista);
}