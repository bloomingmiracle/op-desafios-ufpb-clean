#include <stdio.h>
#include <string.h>
#include <ctype.h>

void ordenar(char palavra[]) {

    int tamanho = strlen(palavra);

    for (int i = 0; i < tamanho - 1; i++) {

        for (int j = i + 1; j < tamanho; j++) {

            if (palavra[i] > palavra[j]) {

                char temp = palavra[i];
                palavra[i] = palavra[j];
                palavra[j] = temp;
            }
        }
    }
}

int main() {

    FILE *arquivo;

    arquivo = fopen("words.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir words.txt\n");
        return 1;
    }

    char entrada[100];
    char entrada_ordenada[100];

    printf("Digite uma palavra: ");
    scanf("%s", entrada);

    for (int i = 0; entrada[i] != '\0'; i++) {
        entrada[i] = tolower(entrada[i]);
    }

    strcpy(entrada_ordenada, entrada);

    ordenar(entrada_ordenada);

    char palavra[100];
    char palavra_ordenada[100];

    printf("\nAnagramas encontrados:\n");

    while (fscanf(arquivo, "%s", palavra) != EOF) {

        for (int i = 0; palavra[i] != '\0'; i++) {
            palavra[i] = tolower(palavra[i]);
        }

        strcpy(palavra_ordenada, palavra);

        ordenar(palavra_ordenada);

        if (strcmp(entrada_ordenada, palavra_ordenada) == 0) {

            if (strcmp(entrada, palavra) != 0) {
                printf("%s\n", palavra);
            }
        }
    }

    fclose(arquivo);

    return 0;
}
