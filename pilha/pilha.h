#include "../lista-ligada/listaligada.h"

typedef struct {
    p_no topo;
} Pilha;

typedef Pilha * p_pilha;

p_pilha criar_pilha();
void destruir_pilha();
void imprimir_pilha(p_pilha p);
void empilhar(p_pilha p); // push
int desempilhar(p_pilha p); // pop