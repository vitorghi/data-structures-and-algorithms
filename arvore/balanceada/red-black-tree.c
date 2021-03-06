/*
Implementação de uma árvore rubro-negra esquerdista
(Left-leaning red-black tree)

Busca, inserção e remoção em O(lg n)

Uma árvore rubro-negra esquerdista é uma ABB tal que:
    1. Todo nó é ou vermelho ou preto
    2. A raiz é preta
    3. As folhas são NULL e tem cor preta
    4. Se um nó é vermelho, seus dois filhos são pretos
        – ele é o filho esquerdo do seu pai (por isso, esquerdista)
    5. Em cada nó, todo caminho dele para uma de suas folhas
       descendentes tem a mesma quantidade de nós pretos
        – Não contamos o nó
        – É a altura-negra do nó
*/

#include <stdlib.h>
#include <stdio.h>
#include "red-black-tree.h"

int ehVermelho(p_no x) {
    if (x == NULL)
        return 0;
    return x->cor == VERMELHO;
}

int ehPreto(p_no x) {
    if (x == NULL)
        return 1;
    return x->cor == PRETO;
}

p_no rotaciona_para_esquerda(p_no raiz) {
    p_no x = raiz->dir;
    raiz->dir = x->esq;
    x->esq = raiz;
    x->cor = raiz->cor;
    raiz->cor = VERMELHO;
    return x;
}

p_no rotaciona_para_direita(p_no raiz) {
    p_no x = raiz->esq;
    raiz->esq = x->dir;
    x->dir = raiz;
    x->cor = raiz->cor;
    raiz->cor = VERMELHO;
    return x;
}

void sobe_vermelho(p_no raiz) {
    raiz->cor = VERMELHO;
    raiz->esq->cor = PRETO;
    raiz->dir->cor = PRETO;
}

p_no inserir_rec(p_no raiz, int chave) {
    if (raiz == NULL) {
        p_no novo = malloc(sizeof(No));
        novo->chave = chave;
        novo->cor =  VERMELHO;
        novo->esq = novo->dir = NULL;
        return novo;
    }
    if (chave < raiz->chave)
        raiz->esq = inserir_rec(raiz->esq, chave);
    else
        raiz->dir = inserir_rec(raiz->dir, chave);

    // corrigindo a árvore:
    if (ehVermelho(raiz->dir) && ehPreto(raiz->esq))
        raiz = rotaciona_para_esquerda(raiz);
    if (ehVermelho(raiz->esq) && ehVermelho(raiz->esq->esq))
        raiz = rotaciona_para_direita(raiz);
    if(ehVermelho(raiz->esq) && ehVermelho(raiz->dir))
        sobe_vermelho(raiz);

    return raiz;
}

p_no inserir(p_no raiz, int chave) {
    raiz = inserir_rec(raiz, chave);
    raiz->cor = PRETO; // Corrige propriedade da raiz ser sempre PRETA
    return raiz;
}