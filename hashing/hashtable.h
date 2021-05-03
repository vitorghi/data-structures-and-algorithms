#define MAX 1783

typedef struct No {
    char *chave;
    int dado;
    struct No * prox;
} No;
typedef No * p_no;

typedef struct {
    p_no vetor[MAX];
} Hash;
typedef Hash * p_hash;

p_hash criar_hash();
void destruir_hash(p_hash t);
int hash(char *chave);
void inserir(p_hash t, char *chave, int dado);
void remover(p_hash t, char *chave);
p_no buscar(p_hash t, char *chave);

// Operações lista ligada
p_no inserir_lista(p_no lista, char *chave, int x);
p_no remover_lista(p_no lista, char *chave);
p_no busca_elemento_lista(p_no lista, char *chave);
void destruir_lista(p_no lista);
