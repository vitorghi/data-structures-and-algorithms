/* Tipo Abstrato de Dados:
    Um conjunto de valores associado a um conjunto de operações
    permitidas nesses dados

• Interface : conjunto de operações de um TAD
    – Consiste dos nomes e demais convenções usadas para executar cada operação
• Implementação : conjunto de algoritmos que realizam as operações
    – A implementação é o único “lugar” que uma variável é acessada diretamente
• Cliente : código que utiliza / chama uma operação
    – O cliente nunca acessa a variável diretamente


Como compilar? Temos três arquivos diferentes:
    • aula05.c contém a função main
    • aula05-impl.c contém a implementação
    • aula05.h contém a interface

Vamos compilar por partes:
    • gcc -std=c99 -Wall -Werror -c aula05.c
        – vai gerar o arquivo compilado cliente.o
    • gcc -std=c99 -Wall -Werror -c aula05-impl.c
        – vai gerar o arquivo compilado complexos.o
    • gcc cliente.o complexos.o -lm -o cliente
        – faz a linkagem, gerando o executável cliente
        – adicionamos cliente.o e complexos.o
        – e outras bibliotecas, por exemplo, -lm
*/

#include <stdio.h>
#include "aula05.h"

int main() {
    complexo a, b, c;
    a = complexo_le();
    b = complexo_le();
    c = complexo_soma(a, b);

    complexo_imprime(c);
    printf("%lf\n", complexo_absoluto(c));
    return 0;
}