#include <stdio.h>
#include <stdlib.h>
#include "../representation/grafo-lista.h"
#include "../../fila/fila.h"

void bfs_caminhos(p_grafo g, int *pai, int s) {
    int *visitado = calloc(g->n, sizeof(int));
    p_fila fila = criar_fila();

    enfileirar(fila, s);
    pai[s] = s;
    visitado[s] = 1;

    while(!eh_vazia(fila)) {
        int v = desenfileirar(fila);
        for (p_no w = g->adjacencia[v]; w != NULL; w = w->prox) {
            if (!visitado[w->dado]) {
                visitado[w->dado] = 1;
                pai[w->dado] = v;
                enfileirar(fila, w->dado);
            }
        }
    }

    destruir_fila(fila);
    free(visitado);
    return pai;
}

int * encontra_caminhos(p_grafo g, int s) {
    int *pai = malloc(g->n * sizeof(int));
    for (int i = 0; i < g->n; i++)
        pai[i] = -1;
    bfs_caminhos(g, pai, s);
    return pai;
}