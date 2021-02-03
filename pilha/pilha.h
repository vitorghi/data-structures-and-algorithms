#include "../lista-ligada/listaligada.h"

typedef struct {
    p_no topo;
} Pilha;

typedef Pilha * p_pilha;

p_pilha criar_pilha();
void destruir_pilha(p_pilha p);
void imprimir_pilha(p_pilha p);
void empilhar(p_pilha p, int x); // push
int desempilhar(p_pilha p); // pop
int eh_vazia(p_pilha p);