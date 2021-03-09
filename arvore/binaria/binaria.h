typedef struct No {
    int chave;
    struct No *esq, *dir, *pai; /*pai é opcional , usado em sucessor e antecessor*/
} No;

typedef No * p_no;

p_no criar_arvore();
void destruir_arvore(p_no raiz);
p_no inserir(p_no raiz, int chave);
p_no remover(p_no raiz, int chave);
p_no buscar_recursivo(p_no raiz, int chave);
p_no buscar_iterativo(p_no raiz, int chave);
p_no minimo(p_no raiz);
p_no maximo(p_no raiz);
p_no sucessor(p_no x);
p_no antecessor(p_no x);