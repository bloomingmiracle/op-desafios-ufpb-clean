#include <stdio.h>

int movimentos_x[] = {2,1,-1,-2,-2,-1,1,2};
int movimentos_y[] = {1,2,2,1,-1,-2,-2,-1};

int tabuleiro[8][8];

int valido(int x, int y) {

    return (x >= 0 &&
            x < 8 &&
            y >= 0 &&
            y < 8 &&
            tabuleiro[x][y] == 0);
}

int passeio(int x, int y, int passo) {

    tabuleiro[x][y] = passo;

    if (passo == 64) {
        return 1;
    }

    for (int i = 0; i < 8; i++) {

        int novo_x = x + movimentos_x[i];
        int novo_y = y + movimentos_y[i];

        if (valido(novo_x, novo_y)) {

            if (passeio(novo_x, novo_y, passo + 1)) {
                return 1;
            }
        }
    }

    tabuleiro[x][y] = 0;

    return 0;
}

int main() {

    char entrada[3];

    printf("Digite posição inicial: ");
    scanf("%s", entrada);

    int y = entrada[0] - 'a';
    int x = entrada[1] - '1';

    if (passeio(x, y, 1)) {

        for (int passo = 1; passo <= 64; passo++) {

            for (int i = 0; i < 8; i++) {

                for (int j = 0; j < 8; j++) {

                    if (tabuleiro[i][j] == passo) {

                        printf("%c%d\n", j + 'a', i + 1);
                    }
                }
            }
        }
    }

    else {

        printf("Sem solução.\n");
    }

    return 0;
}
