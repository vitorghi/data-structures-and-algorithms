#include <stdio.h>

// Eliminando recursão de cauda.
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