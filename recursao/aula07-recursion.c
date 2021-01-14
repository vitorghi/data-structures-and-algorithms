/* Recursão
A ideia é que um problema pode ser resolvido da seguinte maneira:
    • Primeiro, definimos as soluções para casos básicos
    • Em seguida, tentamos reduzir o problema para instâncias menores do problema
    • Finalmente, combinamos o resultado das instâncias menores para obter um resultado do problema original

Caso base:
    • resolve instâncias pequenas diretamente
Caso geral:
    • reduz o problema para instâncias menores do mesmo problema
    • chama a função recursivamente
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fatorial
int fact(int n) {
    if (n == 0)
        return 1;
    return n * fact(n - 1);
}

// Progressão aritmética
int pa(int a_1, int r, int n) {
    if (n == 1) {
        printf("pa_base: %d\n", a_1);
        return a_1;
    }
    int atual = r + pa(a_1, r , n - 1);
    printf("pa_atual: %d\n", atual);
    return atual;
}

// Fibonacci
int fib(int n) {
    if(n == 1 || n == 2)
        return 1;
    return fib(n - 1) + fib(n - 2);
}

// Algoritmo de euclides, maior divisor comum
int gcd(int a, int b) {
    if (b ==0)
        return a;
    return gcd(b, a % b);
}

int soma(int n){
    if (n == 1)
        return 1;
    return n + soma(n - 1);
}

int soma_impar(int n) {
    if(n == 1)
        return 1;
    if (n % 2 != 0)
        return n + soma_impar(n - 1);
    return soma_impar(n - 1);
}

int palindromo(char *s, int inicio, int fim) {
    if (inicio >= fim)
        return 1;

    return (s[inicio] == s[fim]) &&
        palindromo(s, inicio+1, fim-1);
}

int maximoR(int *v, int n, int maximo) {
    if (v[n] > maximo)
        maximo = v[n];
    if (n == 0)
        return maximo;
    return maximoR(v, n - 1, maximo);
}

int maximo(int *v, int n) {
    return maximoR(v, n, 0);
}

int main() {
    pa(3, 5, 4);
    printf("fact: %d\n", fact(4));
    printf("soma: %d\n", soma(5));
    printf("soma_impar: %d\n", soma_impar(8));
    return 0;
}