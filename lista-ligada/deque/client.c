#include <stdio.h>
#include "deque.h"

int main() {
    p_deque deque = criar_deque();
    insere_inicio(deque, 1);
    insere_inicio(deque, 2);
    insere_inicio(deque, 3);
    insere_inicio(deque, 4);
    insere_fim(deque, 5);

    remove_inicio(deque);
    remove_fim(deque);

    printf("inicio: %d\n", deque->ini->dado);
    printf("fim: %d\n", deque->fim->dado);

    imprimir_deque(deque);
    destruir_deque(deque);

    return 0;
}