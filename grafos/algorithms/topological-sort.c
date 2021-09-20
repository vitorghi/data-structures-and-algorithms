#include "../representation/grafo-lista.h"
#include <stdio.h>
#include <stdlib.h>

void dfs(int *visitados, p_grafo g, int v) {
    visitados[v] = 1;

    for (p_no t = g->adjacencia[v]; t != NULL; t = t->prox)
        if (!visitados[t->v])
            dfs(visitados, g, t->v);

    printf("%d ", v);
}

void topological_sort(p_grafo g) {
    int s, *visitados = malloc(g->n * sizeof(int));
    for (s = 0; s < g->n; s++)
        visitados[s] = 0;

    for (s = 0; s < g->n; s++)
        if (!visitados[s])
            dfs(visitados, g, s);

    printf("\n");
    free(visitados);
}

int main() {
    p_grafo g = le_digrafo();
    topological_sort(g);

    destroi_grafo(g);
    return 0;
}