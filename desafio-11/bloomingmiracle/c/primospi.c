#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int eh_primo(int numero) {

    if (numero < 2) {
        return 0;
    }

    for (int i = 2; i * i <= numero; i++) {

        if (numero % i == 0) {
            return 0;
        }
    }

    return 1;
}

int main() {

    FILE *arquivo;

    arquivo = fopen("pi.txt", "r");

    if (arquivo == NULL) {

        printf("Erro ao abrir arquivo.\n");
        return 1;
    }

    char pi[10000];

    fgets(pi, sizeof(pi), arquivo);

    fclose(arquivo);

    char resultado[10000] = "";

    int tamanho = strlen(pi);

    for (int i = 2; i < tamanho; ) {

        int encontrou = 0;

        for (int tamanho_numero = 4; tamanho_numero >= 1; tamanho_numero--) {

            if (i + tamanho_numero <= tamanho) {

                char temp[10];

                strncpy(temp, &pi[i], tamanho_numero);

                temp[tamanho_numero] = '\0';

                int numero = atoi(temp);

                if (eh_primo(numero)) {

                    strcat(resultado, temp);

                    i += tamanho_numero;

                    encontrou = 1;

                    break;
                }
            }
        }

        if (!encontrou) {
            i++;
        }
    }

    printf("%s\n", resultado);

    return 0;
}
