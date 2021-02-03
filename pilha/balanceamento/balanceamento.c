#include <stdio.h>
#include "../pilha.h"

int eh_balanceada(char *str) {
    p_pilha pilha = criar_pilha();
    int balanceada = 1;

    for (int i = 0; balanceada && str[i] != '\0'; i++)
        if (str[i] == '(' || str[i] == '[')
            empilhar(pilha, str[i]);
        else if (eh_vazia(pilha))
            balanceada = 0;
        else {
            char par = desempilhar(pilha);
            if (str[i] == ']' && par != '[')
                balanceada = 0;
            if (str[i] == ')' && par != '(')
                balanceada = 0;
        }

    if (!eh_vazia(pilha))
        balanceada = 0;

    destruir_pilha(pilha);
    return balanceada;
}

int main() {
    char str[100];
    printf("entre com a string para checar o balanceamento: \n");
    scanf("%s", str);

    printf("eh balanceada: %d\n", eh_balanceada(str));
    return 0;
}