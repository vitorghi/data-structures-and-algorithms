/*
• Declare uma struct que armazena informações de notas de
uma turma. Essa estrutura deve armazenar o número de
alunos, as notas das provas e a maior nota.

• Depois faça um programa que leia todos os dados e imprima a
maior nota.
*/
#include <stdio.h>
#include <stdlib.h>

int le_numero_alunos();
double * aloca_notas(int numero_alunos);
double calcula_maior_nota(double *notas, int n);

typedef struct {
    int numero_alunos;
    double *notas;
    double maior_nota;
} turma;

int main() {
    turma t;
    t.numero_alunos = le_numero_alunos();
    t.notas = aloca_notas(t.numero_alunos);
    t.maior_nota = calcula_maior_nota(t.notas, t.numero_alunos);
    printf("a maior nota é: %lf\n", t.maior_nota);
    free(t.notas);
}

int le_numero_alunos() {
    int n;
    printf("Entre com o numero de alunos da turma: \n");
    scanf("%d", &n);
    return n;
}

double *aloca_notas(int numero_alunos) {
    double *notas = malloc(numero_alunos * sizeof(double));
    if (notas == NULL) exit(1);

    printf("Entre com as notas dos alunos da turma: \n");
    for (int i = 0; i < numero_alunos; i++)
        scanf("%lf", &notas[i]);

    return notas;
}

double calcula_maior_nota(double *notas, int n) {
    double max = 0;
    for (int i = 0; i < n; i++)
        if (max < notas[i]) max = notas[i];
    return max;
}
