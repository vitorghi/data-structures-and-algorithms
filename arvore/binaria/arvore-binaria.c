/*
Tempo para Inserção, Remoção e Busca

  Usando Listas Duplamente Ligadas:
    • Podemos inserir e remover em O(1)
    • Mas buscar demora O(n)
  Se usarmos vetores não-ordenados:
    • Podemos inserir e remover em O(1)
      – insira no final
      – para remover, troque com o último e remova o último
    • Mas buscar demora O(n)
  Se usarmos vetores ordenados:
    • Podemos buscar em O(lg n)
    • Mas inserir e remover leva O(n)
  Árvores binárias de busca:
    • primeiro uma versão simples, depois uma sofisticada
    • versão sofisticada: três operações levam O(lg n)


Uma Árvore Binária de Busca (ABB) é uma árvore binária em que
cada nó contém um elemento de um conjunto ordenável

Cada nó r, com subárvores esquerda Te e direita Td satisfaz a
seguinte propriedade:
    1. e < r para todo elemento e ∈ Te
    2. d > r para todo elemento d ∈ Td
*/

#include <stdio.h>
#include <stdlib.h>
#include "binaria.h"

// Para a busca, é usado a mesma ideia da busca binária.
p_no buscar_recursivo(p_no raiz, int chave) {
    if (raiz == NULL || chave == raiz->chave)
        return raiz;
    if (chave < raiz->chave)
        return buscar(raiz->esq, chave);
    else
        return buscar(raiz->dir, chave);
}

p_no buscar_recursivo(p_no raiz, int chave) {
    while (raiz != NULL && chave != raiz->chave)
        if (chave < raiz->chave)
            raiz = raiz->esq;
        else
            raiz = raiz->dir;
    return raiz;
}

p_no inserir(p_no raiz, int chave) {
    p_no novo;
    if (raiz == NULL) {
        novo = malloc(sizeof(No));
        novo->esq = novo->dir = NULL;
        novo->chave = chave;
        return novo;
    }
    if (chave < raiz->chave)
        raiz->esq = inserir(raiz->esq, chave);
    else
        raiz->dir = inserir(raiz->dir, chave);
    return raiz;
}

p_no minimo(p_no raiz) {
    if (raiz == NULL || raiz->esq == NULL)
        return raiz;
    return minimo(raiz->esq);
}

p_no minimo_iterativo(p_no raiz) {
    while (raiz != NULL && raiz->esq != NULL)
        raiz = raiz->esq;
    return raiz;
}

p_no maximo(p_no raiz) {
    if (raiz == NULL || raiz->dir == NULL)
        return raiz;
    return maximo(raiz->dir);
}

p_no maximo_iterativo(p_no raiz) {
    while (raiz != NULL && raiz->dir != NULL)
        raiz = raiz->dir;
    return raiz;
}
