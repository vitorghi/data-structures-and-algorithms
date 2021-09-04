#include "grafo.h"

int main() {
    p_grafo g = le_grafo();

    recomendacoes(g, 0);

    destroi_grafo(g);
    return 0;
}