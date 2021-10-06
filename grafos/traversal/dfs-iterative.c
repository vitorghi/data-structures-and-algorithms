#include <stdio.h>
#include <stdlib.h>
#include "../representation/grafo-lista.h"
#include "../../pilha/pilha.h"

void dfs_caminhos(p_grafo g, int *pai, int s) {
    int *visitado = calloc(g->n, sizeof(int));
    p_pilha pilha = criar_pilha();

    empilhar(pilha, s);
    pai[s] = s;

    while(!eh_vazia(pilha)) {
        int v = desempilhar(pilha);
        visitado[v] = 1;
        for (p_no w = g->adjacencia[v]; w != NULL; w = w->prox) {
            if (!visitado[w->dado]) {
                pai[w->dado] = v;
                empilhar(pilha, w->dado);
            }
        }
    }

    destruir_pilha(pilha);
    free(visitado);
    return pai;
}

int * encontra_caminhos(p_grafo g, int s) {
    int *pai = malloc(g->n * sizeof(int));
    for (int i = 0; i < g->n; i++)
        pai[i] = -1;
    dfs_caminhos(g, pai, s);
    return pai;
}