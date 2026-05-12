#include <stdio.h>
#include <string.h>
#include <math.h>

char caracteres[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

int valor_caractere(char c) {

    for (int i = 0; i < 62; i++) {

        if (caracteres[i] == c) {
            return i;
        }
    }

    return -1;
}

void inverter(char texto[]) {

    int inicio = 0;
    int fim = strlen(texto) - 1;

    while (inicio < fim) {

        char temp = texto[inicio];
        texto[inicio] = texto[fim];
        texto[fim] = temp;

        inicio++;
        fim--;
    }
}

int main() {

    FILE *arquivo;

    arquivo = fopen("entrada.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo.\n");
        return 1;
    }

    int base_entrada;
    int base_saida;

    char numero[100];

    while (fscanf(arquivo, "%d %d %s",
           &base_entrada,
           &base_saida,
           numero) != EOF) {

        long long decimal = 0;

        int tamanho = strlen(numero);

        for (int i = 0; i < tamanho; i++) {

            int valor = valor_caractere(numero[i]);

            decimal = decimal * base_entrada + valor;
        }

        char resultado[100];
        int indice = 0;

        if (decimal == 0) {

            resultado[indice++] = '0';
        }

        while (decimal > 0) {

            int resto = decimal % base_saida;

            resultado[indice++] = caracteres[resto];

            decimal = decimal / base_saida;
        }

        resultado[indice] = '\0';

        inverter(resultado);

        printf("%s\n", resultado);
    }

    fclose(arquivo);

    return 0;
}
