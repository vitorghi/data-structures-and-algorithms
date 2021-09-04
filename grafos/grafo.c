#include <stdlib.h>
#include <stdio.h>
#include "grafo.h"

p_grafo criar_grafo(int n) {
    p_grafo g = malloc(sizeof(Grafo));
    g->n = n;
    g->adjacencia = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        g->adjacencia[i] = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        g->adjacencia[i][j] = 0;

    return g;
}

void destroi_grafo(p_grafo g) {
    for(int i = 0; i < g->n; i++)
        free(g->adjacencia[i]);
    free(g->adjacencia);
    free(g);
}

void insere_aresta(p_grafo g, int u, int v) {
    g->adjacencia[u][v] = 1;
    g->adjacencia[v][u] = 1;
}

void remove_aresta(p_grafo g, int u, int v){
    g->adjacencia[u][v] = 0;
    g->adjacencia[v][u] = 0;
}

int tem_aresta(p_grafo g, int u, int v) {
    return g->adjacencia[u][v];
}

p_grafo le_grafo() {
    int n_vertices, n_arestas, u, v;
    scanf("%d %d", &n_vertices, &n_arestas);
    p_grafo g = criar_grafo(n_vertices);

    for (int i = 0; i < n_arestas; i++) {
        scanf("%d %d", &u, &v);
        insere_aresta(g, u , v);
    }
    return g;
}

void imprime_arestas(p_grafo g) {
    for(int u = 0; u < g->n; u++)
        for(int v = u + 1; v < g->n; v++)
            if(g->adjacencia[u][v])
                printf("{ %d, %d }\n", u, v);
}

int grau(p_grafo g, int u) {
    int v, grau = 0;
    for (v = 0; v < g->n; v++)
        if (tem_aresta(g, u, v))
            grau++;
    return grau;
}

int mais_popular(p_grafo g) {
    int u, max, grau_max, grau_atual;
    max = 0;
    grau_max = grau(g, 0);

    for(u = 1; u < g->n; u++) {
        grau_atual = grau(g, u);
        if (grau_atual > grau_max) {
            grau_max = grau_atual;
            max = u;
        }
    }
    return max;
}

void recomendacoes(p_grafo g, int u) {
    int v, w;
    for (v = 0; v < g->n; v++) {
        if (tem_aresta(g, u, v)) {
            for (w = 0; w < g->n; w++) {
                if (tem_aresta(g, v, w) && w != u && !tem_aresta(g, u, w))
                    printf("%d\n ", w);
            }
        }
    }
}