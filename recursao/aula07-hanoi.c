#include <stdio.h>

void hanoi(int n, char orig, char dest, char aux) {
    if (n > 0) {
        hanoi(n - 1, orig, aux, dest);
        printf("move de %c para %c \n", orig, dest);
        hanoi(n - 1, aux, dest, orig);
    }
}

int main() {
    hanoi(3, 'a', 'b', 'c');
}
