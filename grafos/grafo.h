typedef struct {
    int **adjacencia;
    int n;
} Grafo;

typedef Grafo * p_grafo;

p_grafo criar_grafo(int n);

void destroi_grafo(p_grafo g);

void insere_aresta(p_grafo g, int u, int v);

void remove_aresta(p_grafo g, int u, int v);

int tem_aresta(p_grafo g, int u, int v);

p_grafo le_grafo();

void imprime_arestas(p_grafo g);

int grau(p_grafo g, int u);

int mais_popular(p_grafo g);

void recomendacoes(p_grafo g, int u);
