#include <stdio.h>
#include "../pilha.h"
/*
infixa: : é a notação cotidiana
    – Ordem normal de leitura, com parênteses para evitar ambiguidade

pré-fixa: é a notação polonesa do lógico Jan Lukasiewicz
    – Operador precede operandos

pós-fixa: é notação polonesa reversa (RPN), das calculadoras HP, ...
    – Operador sucede operandos

Exemplo 1:
    • Infixa: a + b
    • Pré-fixa: + a b
    • Pós-fixa: a b +

Exemplo 2:
    • Infixa: 5 * ( (9 + 8) * 4 * 6 + 7)
    • Pré-fixa: * 5 + * + 9 8 * 4 6 7
    • Pós-fixa: 5 9 8 + 4 6 * * 7 + *
*/

int calculo_pos_fixa(char *expressao) {
    p_pilha pilha = criar_pilha();
    int empilhado;
    for (int i = 0; expressao[i] != '\0'; i++) {
        switch (expressao[i]) {
            case '+':
                empilhado = desempilhar(pilha) + desempilhar(pilha);
                printf("empilhando +: %d\n", empilhado);
                empilhar(pilha, empilhado);
                break;
            case '*':
                empilhado = desempilhar(pilha) * desempilhar(pilha);
                printf("empilhando *: %d\n", empilhado);
                empilhar(pilha, empilhado);
                break;
            default:
                empilhado = expressao[i] - '0'; // e.g.: turns char '1' into int '1'
                printf("empilhando numero: %d\n", empilhado);
                empilhar(pilha, empilhado);
                break;
        }
    }
    imprimir_pilha(pilha);
    int resultado = desempilhar(pilha);
    destruir_pilha(pilha);
    return resultado;
}

int main() {
    char str[100];
    printf("entre com a expressao pós-fixa: \n");
    scanf("%s", str);
    printf("expressao: %s\n", str);

    printf("resultado: %d\n", calculo_pos_fixa(str));
    return 0;
}

// exercício: converter infixa para pos-fixa