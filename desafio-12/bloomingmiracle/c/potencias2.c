#include <stdio.h>

int main() {

    FILE *arquivo;

    arquivo = fopen("numeros.txt", "r");

    if (arquivo == NULL) {

        printf("Erro ao abrir arquivo.\n");
        return 1;
    }

    unsigned long long numero;

    while (fscanf(arquivo, "%llu", &numero) != EOF) {

        unsigned long long temp = numero;

        int expoente = 0;

        int potencia = 1;

        if (numero == 0) {
            potencia = 0;
        }

        while (temp > 1) {

            if (temp % 2 != 0) {

                potencia = 0;
                break;
            }

            temp = temp / 2;

            expoente++;
        }

        if (potencia) {

            printf("%llu true %d\n", numero, expoente);
        }

        else {

            printf("%llu false\n", numero);
        }
    }

    fclose(arquivo);

    return 0;
}
