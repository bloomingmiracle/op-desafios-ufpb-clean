#include <stdio.h>
#include <string.h>

typedef struct {

    char estado_atual[20];
    char simbolo_atual;
    char novo_simbolo;
    char direcao;
    char novo_estado[20];

} Regra;

int main() {

    FILE *arquivo_dados;
    FILE *arquivo_regras;

    arquivo_dados = fopen("dados.txt", "r");
    arquivo_regras = fopen("regras.txt", "r");

    if (arquivo_dados == NULL || arquivo_regras == NULL) {

        printf("Erro ao abrir arquivos.\n");
        return 1;
    }

    char fita[1000] = "_";
    char entrada[500];

    fgets(entrada, sizeof(entrada), arquivo_dados);

    entrada[strcspn(entrada, "\n")] = '\0';

    strcat(fita, entrada);
    strcat(fita, "_");

    Regra regras[100];
    int total_regras = 0;

    while (fscanf(arquivo_regras,
           "%s %c %c %c %s",
           regras[total_regras].estado_atual,
           &regras[total_regras].simbolo_atual,
           &regras[total_regras].novo_simbolo,
           &regras[total_regras].direcao,
           regras[total_regras].novo_estado) != EOF) {

        total_regras++;
    }

    char estado[20] = "0";

    int posicao = 1;

    while (strcmp(estado, "halt") != 0) {

        char simbolo = fita[posicao];

        int encontrou = 0;

        for (int i = 0; i < total_regras; i++) {

            if (strcmp(estado, regras[i].estado_atual) == 0 &&
                simbolo == regras[i].simbolo_atual) {

                fita[posicao] = regras[i].novo_simbolo;

                if (regras[i].direcao == 'r') {
                    posicao++;
                }

                else if (regras[i].direcao == 'l') {
                    posicao--;
                }

                strcpy(estado, regras[i].novo_estado);

                encontrou = 1;

                break;
            }
        }

        if (!encontrou) {
            break;
        }
    }

    printf("Fita final: %s\n", fita);

    fclose(arquivo_dados);
    fclose(arquivo_regras);

    return 0;
}
