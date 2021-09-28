#include <stdio.h>
#include <stdlib.h>
#include "../representation/grafo-lista.h"

int dfs(p_grafo g, int v, int t, int *visitados) {
    printf("%d ", v);
    if (v == t)
        return 1;

    visitados[v] = 1;
    for(p_no u = g->adjacencia[v]; u != NULL; u = u->prox) {
        if (!visitados[u->v] && dfs(g, u->v, t, visitados))
            return 1;
    }
    return 0;
}

int ha_caminho(p_grafo g, int s, int t) {
    int *visitados = malloc(g->n * sizeof(int));
    for(int i = 0; i < g->n; i++)
        visitados[i] = 0;

    int ha_caminho = dfs(g, s, t, visitados);
    free(visitados);
    return ha_caminho;
}

void dfs_caminhos(p_grafo g, int *pai, int p, int v) {
    pai[v] = p;
    for (p_no t = g->adjacencia[v]; t != NULL; t = t->prox)
        if (pai[t->v] == -1)
            dfs_caminhos(g, pai, v, t->v);
}

int * encontra_caminhos(p_grafo g, int s) {
    int *pai = malloc(g->n * sizeof(int));
    for (int i = 0; i < g->n; i++)
        pai[i] = -1;
    dfs_caminhos(g, pai, s, s);
    return pai;
}

void imprime_caminho(int *pai, int v) {
    if (pai[v] != v)
        imprime_caminho(pai, pai[v]);
    printf("%d ", v);
}

void imprime_caminho_reverso(int *pai, int v) {
    printf("%d ", v);
    if (pai[v] != v)
        imprime_caminho_reverso(pai, pai[v]);
}

int main() {
    int s = 0;
    int t = 4;
    p_grafo g = le_grafo();

    int encontrou = ha_caminho(g, s, t);
    char *encontrou_string = encontrou ? "SIM" : "NAO";
    printf("ha caminho entre s:%d e t:%d? %s\n", s, t, encontrou_string);

    int *caminhos = encontra_caminhos(g, 0);
    imprime_caminho(caminhos, 7);
    printf("\n");
    imprime_caminho_reverso(caminhos, 7);
    printf("\n");
    free(caminhos);

    destroi_grafo(g);
    return 0;
}
