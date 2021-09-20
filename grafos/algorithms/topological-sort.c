#include "representation/grafo-lista.h"
#include <stdio.h>
#include <stdlib.h>

void dfs(int *visitados, p_no no, int v) {
    visitados[v] = 1;

    for (p_no adj = no; adj != NULL; adj = adj->prox) {
        if (!visitados[v])
            dfs(*visitados, adj, adj->v);
    }
    printf("%d ", no->v);
}

void topological_sort(p_grafo g) {
    int *visitados = malloc(g->n * sizeof(int));
    for (int i = 0; i < g->n; i++)
        visitados[i] = 0;

    for (int i = 0; i < g->n; i++)
        if (!visitados[i])
            dfs(visitados, g->adjacencia[i], i);

    printf("\n");
    free(visitados);
}

int main() {
    p_grafo g = le_grafo();
    topological_sort(g);

    return 0;
}