#include <stdio.h>

int main() {

    FILE *arquivo;

    arquivo = fopen("expressoes.txt", "r");

    if (arquivo == NULL) {

        printf("Erro ao abrir arquivo.\n");
        return 1;
    }

    int a;
    int b;
    char operador;

    while (fscanf(arquivo, "%d%c%d", &a, &operador, &b) == 3) {

        if (operador == '+') {

            printf("%d\n", a + b);
        }

        else if (operador == '-') {

            printf("%d\n", a - b);
        }

        else if (operador == '*') {

            printf("%d\n", a * b);
        }

        else if (operador == '/') {

            if (b == 0) {

                printf("ERR DIVBYZERO\n");
            }

            else {

                printf("%d\n", a / b);
            }
        }

        else {

            printf("ERR SYNTAX\n");
        }
    }

    fclose(arquivo);

    return 0;
}
