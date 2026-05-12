#include <stdio.h>

int main() {

    int tabuleiro[8][8];

    int peao = 0;
    int bispo = 0;
    int cavalo = 0;
    int torre = 0;
    int rainha = 0;
    int rei = 0;

    for (int i = 0; i < 8; i++) {

        for (int j = 0; j < 8; j++) {

            scanf("%d", &tabuleiro[i][j]);

            peao += (tabuleiro[i][j] == 1);
            bispo += (tabuleiro[i][j] == 2);
            cavalo += (tabuleiro[i][j] == 3);
            torre += (tabuleiro[i][j] == 4);
            rainha += (tabuleiro[i][j] == 5);
            rei += (tabuleiro[i][j] == 6);
        }
    }

    printf("Peão: %d peça(s)\n", peao);
    printf("Bispo: %d peça(s)\n", bispo);
    printf("Cavalo: %d peça(s)\n", cavalo);
    printf("Torre: %d peça(s)\n", torre);
    printf("Rainha: %d peça(s)\n", rainha);
    printf("Rei: %d peça(s)\n", rei);

    return 0;
}
