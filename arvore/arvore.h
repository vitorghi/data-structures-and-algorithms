typedef struct No {
    int dado;
    struct No *esq, *dir; // *pai
} No;

typedef No * p_no;

p_no criar_arvore(int x, p_no esq, p_no dir);

p_no procurar_no(p_no raiz, int x);

int numero_nos(p_no raiz);

int altura(p_no raiz);

void imprime_pre_ordem(p_no raiz);

void imprime_pos_ordem(p_no raiz);

void imprime_in_ordem(p_no raiz);