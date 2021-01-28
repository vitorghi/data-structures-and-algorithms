#include "../lista-ligada/listaligada.h"

typedef struct {
    p_no ini, fim;
} Fila;

typedef Fila * p_fila;

p_fila criar_fila();
void destruir_fila();
void imprimir_fila(p_fila f);
void enfileirar(p_fila f, int x);
int desenfileirar(p_fila f);