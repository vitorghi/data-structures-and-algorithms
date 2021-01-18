typedef struct No {
    int dado;
    struct No *prox;
} No;

typedef struct No * p_no;

p_no criar_lista();
p_no adicionar_elemento(p_no lista, int x);

void destruir_lista_rec(p_no lista);
void destruir_lista_iter(p_no lista);

p_no busca_elemento_rec(p_no lista, int x);
p_no busca_elemento_iter(p_no lista, int x);

void imprime_lista_rec(p_no lista);
void imprime_lista_iter(p_no lista);

p_no remove_ocorrencias(p_no lista, int x);
p_no remove_elemento(p_no lista, int x);

p_no copiar_lista_rec(p_no lista);
p_no copiar_lista_iter(p_no lista);

p_no inverter_lista_rec(p_no lista);
p_no inverter_lista_iter(p_no lista);

p_no concatenar_listas_rec(p_no primeira, p_no segunda);
p_no concatenar_listas_iter(p_no primeira, p_no segunda);