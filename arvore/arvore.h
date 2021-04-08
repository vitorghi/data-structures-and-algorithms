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

void percurso_em_largura(p_no raiz);


// Lista ligada
typedef struct No_Lista {
    p_no dado;
    struct No_Lista *prox;
} No_Lista;

typedef struct No_Lista * p_no_lista;
void imprime_lista_rec(p_no_lista lista);
void destruir_lista_rec(p_no_lista lista);

// Fila
typedef struct {
    p_no_lista ini, fim;
} Fila;

typedef Fila * p_fila;
p_fila criar_fila();
void destruir_fila();
void imprimir_fila(p_fila f);
void enfileirar(p_fila f, p_no x);
p_no desenfileirar(p_fila f);
int eh_vazia(p_fila f);
