#include <stdio.h>
#include <stdlib.h>
#include "../representation/grafo-lista.h"

void dfs(p_grafo g, int *componentes, int v, int componente_atual) {
    componentes[v] = componente_atual;
    for(p_no t = g->adjacencia[v]; t != NULL; t = t->prox) {
        if (componentes[t->v] == -1)
            dfs(g, componentes, t->v, componente_atual);
    }
}

int * componente_conexa(p_grafo g) {
    int componente_atual = 0, *componentes = malloc(g-> n * sizeof(int));
    for(int i = 0; i < g->n; i++)
        componentes[i] = -1;

    for(int i = 0; i < g->n; i++) {
        if (componentes[i] == -1) {
            dfs(g, componentes, i, componente_atual);
            componente_atual++;
        }
    }

    return componentes;
}

int main() {
    p_grafo g = le_digrafo();

    int *componentes = componente_conexa(g);
    for (int i = 0; i < g->n; i++)
        printf("%d, %d\n", i, componentes[i]);

    free(componentes);
    destroi_grafo(g);
    return 0;
}
