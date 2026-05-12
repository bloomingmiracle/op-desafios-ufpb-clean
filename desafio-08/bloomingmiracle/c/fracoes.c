#include <stdio.h>

int mdc(int a, int b) {

    while (b != 0) {

        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

int main() {

    FILE *arquivo;

    arquivo = fopen("fracoes.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo.\n");
        return 1;
    }

    char linha[100];

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {

        int numerador;
        int denominador;

        int resultado = sscanf(linha, "%d/%d", &numerador, &denominador);

        if (resultado == 1) {

            printf("%d\n", numerador);
        }

        else if (resultado == 2) {

            if (denominador == 0) {

                printf("ERR\n");
            }

            else {

                int inteiro = numerador / denominador;
                int resto = numerador % denominador;

                if (resto == 0) {

                    printf("%d\n", inteiro);
                }

                else {

                    int divisor = mdc(resto, denominador);

                    resto = resto / divisor;
                    denominador = denominador / divisor;

                    if (inteiro == 0) {

                        printf("%d/%d\n", resto, denominador);
                    }

                    else {

                        printf("%d %d/%d\n", inteiro, resto, denominador);
                    }
                }
            }
        }
    }

    fclose(arquivo);

    return 0;
}
