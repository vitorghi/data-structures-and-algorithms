typedef struct No {
    int dado;
    struct No *prox;
    struct No *ant;
} No;

typedef struct No * p_no;

typedef struct {
    p_no ini, fim;
} Deque;

typedef Deque * p_deque;

p_deque criar_deque();
void destruir_deque(p_deque deque);
void imprimir_deque(p_deque deque);
p_deque insere_inicio(p_deque deque, int x);
p_deque insere_fim(p_deque deque, int x);
int remove_inicio(p_deque deque);
int remove_fim(p_deque deque);