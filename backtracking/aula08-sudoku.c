#include <stdio.h>

int pode_inserir(int m[9][9], int l, int c, int v) {
    int i, j, cel_l, cel_c;
    for (i = 0; i < 9; i++)
        if (m[l][i] == v) // Aparece na linha l?
            return 0;

    for (i = 0; i < 9; i++)
        if (m[i][c] == v) // Aparece na coluna c?
            return 0;

    cel_l = 3 * (l / 3);
    cel_c = 3 * (c / 3);
    for (i = cel_l; i < cel_l + 3; i++)
        for (j = cel_c; j < cel_c + 3; j++)
            if (m[i][j] == v) // Aparece na célula?
                return 0;

    return 1;
}

void proxima_posicao(int l, int c, int *nl, int *nc) {
    if (c < 8) {
        *nl = l;
        *nc = c + 1;
    } else {
        *nl = l + 1;
        *nc = 0; // Começa na próxima linha, na coluna inicial 0
    }
}

void imprime_sudoku(int m[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++)
            printf("%d ", m[i][j]);
        printf("\n");
    }
}

int sudokuR(int m[9][9], int fixo[9][9], int l, int c) {
    int v, nl, nc;
    if (l == 9) { // caso base
        imprime_sudoku(m);
        return 1;
    }

    proxima_posicao(l, c, &nl, &nc);
    if (fixo[l][c]) // Se possuir valor fixo, não tem ação, apenas ir para a próxima posição.
        return sudokuR(m, fixo, nl, nc);

    for (v = 1; v <= 9; v++) {
        if (pode_inserir(m, l, c, v)) {
            m[l][c] = v;
            if(sudokuR(m, fixo, nl, nc))
                return 1;
        }
    }

    m[l][c] = 0;
    return 0;
}

int sudoku(int m[9][9]) {
    int i, j, fixo[9][9];
    for (i = 0; i < 9; i++)
        for (j = 0; j < 9; j++)
            fixo[i][j] = m[i][j];
    return sudokuR(m, fixo, 0, 0);
}

int main() {
    int m[9][9];

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++)
            m[i][j] = 0;
    }

    m[0][3] = 2;
    m[0][4] = 4;
    m[0][5] = 3;
    m[0][6] = 1;

    m[1][2] = 8;
    m[1][5] = 6;
    m[1][7] = 5;

    m[2][1] = 4;

    m[3][3] = 6;
    m[3][8] = 5;

    m[4][0] = 4;
    m[4][1] = 8;
    m[4][3] = 7;
    m[4][4] = 3;
    m[4][5] = 9;
    m[4][6] = 6;
    m[4][7] = 1;

    m[5][3] = 4;
    m[5][8] = 9;

    m[6][1] = 9;

    m[7][2] = 1;
    m[7][5] = 8;
    m[7][7] = 7;

    m[8][3] = 1;
    m[8][4] = 7;
    m[8][5] = 2;
    m[8][6] = 8;

    sudoku(m);
}