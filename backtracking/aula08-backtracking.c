/*
Backtracking:

Resolver um problema de forma recursiva, podendo tomar decisões erradas
    • Nesse caso, escolhemos outra decisão
Construímos soluções passo-a-passo, retrocedendo se a solução parcial atual não é válida
    • Começamos com uma solução parcial vazia
    • Enquanto for possível, adicionamos um elemento à solução parcial
    • Se encontrarmos uma solução completa, terminamos
    • Se não é possível adicionar mais nenhum elemento à solução parcial, retrocedemos
        – removemos um ou mais elementos da solução parcial
        – e tomamos decisões diferentes das que foram tomadas

• Em geral, mais rápido que a Força Bruta pois eliminamos
    vários candidatos a solução de uma só vez
• Implementação simples, mas pode ser lento para problemas
    onde temos muitas soluções parciais possíveis
Como fazer um algoritmo de Backtracking rápido?
    • Ter um algoritmo para decidir se uma solução parcial pode ser
      estendida para uma solução completa que seja
        – Bom: Evita explorar muitas soluções parciais
        – Rápido: Processa cada solução parcial rapidamente

Para aplicar Backtracking é necessário que o problema tenha um
conceito de solução parcial
    • Problemas de satisfação de restrições
        – Encontrar uma solução que satisfaça as restrições
        – Como o Sudoku, por exemplo
    • Problemas de Otimização Combinatória
        – Conseguimos enumerar as soluções do problema
        – Queremos encontrar a de valor mínimo
    • Programação Lógica (Prolog, por exemplo)
        – Prova automática de teoremas
*/

#include <stdio.h>
#include <stdlib.h>

void imprime_vetor(int *vetor, int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", vetor[i]);
    printf("\n");
}

void sequenciasR(int *seq, int n, int k, int i) {
    if (i == k) {
        imprime_vetor(seq, k);
        return;
    }
    for (int v = 1; v <= n; v++) {
        seq[i] = v;
        sequenciasR(seq, n, k, i + 1);
    }
}

void sequencias(int n, int k) {
    int *seq = malloc(k * sizeof(int));
    sequenciasR(seq, n, k, 0);
    free(seq);
}

int main() {
    sequencias(3, 3);
    return 0;
}