/*
Quando empilhamos:
    • Alocamos espaço para as variáveis locais

Quando desempilhamos:
    • Quando a chamada de fat(n) retorna, apagamos o espaço
      para as variáveis locais
    • Restabelecemos os valores das variáveis locais para o valor que
      tinham antes da chamada

O conjunto de variáveis locais formam um elemento da pilha.
Isto é, a recursão pode ser simulada usando uma pilha de suas
variáveis locais
** Precisamos além de empilhar a variáveis locais, armazenar em qual
linha devemos voltar a execução do código

O registro de ativação de uma função é o conjunto formado por:
    1. Variáveis locais
    2. Endereço de retorno após a chamada
A pilha de execução (ou pilha de chamadas) é a pilha dos registros
de ativação das várias chamadas em execução em um programa

Se o último passo de uma função f(x) é o retorno de f(y) então
    • podemos reiterar a função f(x) usando x = y
    • usando um while
    • até chegar em uma das bases da recursão
Chamamos esse tipo de recursão de recursão de cauda

Recursões que não são de cauda também podem ser eliminadas
    • Porém é necessário utilizar uma pilha
    • E o processo é mais trabalhoso
*/

#include <stdio.h>

int busca_binaria_rec(int *dados, int l, int r, int x) {
    int m = (l + r) / 2;
    if (l > r)
        return -1;
    if (dados[m] == x)
        return m;
    else if (dados[m] < x)
        return busca_binaria_rec(dados, m + 1, r, x);
    else
        return busca_binaria_rec(dados, l, m - 1, x);
}

// Eliminando recursão de cauda.
int busca_binaria_iter(int *dados, int l, int r, int x) {
    while (l <= r) {
        int m = (l + r) / 2;
        if (dados[m] == x)
            return m;
        else if (dados[m] < x)
            l = m++;
        else
            r = m++;
    }
    return -1;
}

int main() {
    int v[] = {1, 2, 3, 4, 5};

    int x = busca_binaria_rec(v, 0, 4, 2);
    int y = busca_binaria_iter(v, 0, 4, 2);

    printf("rec: %d\niter: %d\n", x, y);
    return 0;
}