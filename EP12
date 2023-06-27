#include <stdio.h>

int main() {
    int num_testes;
    scanf("%d", &num_testes);

    while (num_testes > 0) {
        int num_linhas;
        scanf("%d", &num_linhas);

        int i, j;
        char linha[51];
        int hash = 0;

        for (i = 0; i < num_linhas; i++) {
            scanf("%s", linha);
            for (j = 0; linha[j] != '\0'; j++) {
                hash += (linha[j] - 'A') + i + j;
            }
        }

        printf("%d\n", hash);

        num_testes--;
    }

    return 0;
}
