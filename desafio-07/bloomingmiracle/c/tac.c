#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {

    FILE *arquivo;

    arquivo = fopen(argv[1], "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo.\n");
        return 1;
    }

    char linhas[100][1000];
    int total = 0;

    while (fgets(linhas[total], 1000, arquivo) != NULL) {
        total++;
    }

    for (int i = total - 1; i >= 0; i--) {
        printf("%s", linhas[i]);
    }

    fclose(arquivo);

    return 0;
}

