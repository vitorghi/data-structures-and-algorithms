/*
Lista em que o último nó aponta para o primeiro.

Exemplos de aplicações:
    • Execução de processos no sistema operacional
    • Controlar de quem é a vez em um jogo de tabuleiro
*/

typedef struct No {
    int dado;
    struct No *prox;
} No;

typedef struct No * p_no;

p_no criar_lista_circular();
p_no inserir_circular(p_no lista, int x);
p_no remover_circular(p_no lista, p_no no);
void imprimir_circular(p_no lista);