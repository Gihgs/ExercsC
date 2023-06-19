#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PESSOAS 100
#define MAX_TAMANHO_LINGUA 20

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int K;
        scanf("%d", &K);

        char linguagens[MAX_PESSOAS][MAX_TAMANHO_LINGUA + 1];

        for (int i = 0; i < K; i++) {
            scanf("%s", linguagens[i]);
            // Converter a língua para letras minúsculas
            for (int j = 0; linguagens[i][j]; j++) {
                linguagens[i][j] = tolower(linguagens[i][j]);
            }
        }

        int countIngles = 0;
        int countNativo = 0;
        char primeiraLingua[MAX_TAMANHO_LINGUA + 1];
        strcpy(primeiraLingua, linguagens[0]);

        for (int i = 0; i < K; i++) {
            if (strcmp(linguagens[i], "ingles") == 0) {
                countIngles++;
            } else if (strcmp(linguagens[i], primeiraLingua) == 0) {
                countNativo++;
            }
        }

        if (countIngles == K) {
            printf("ingles\n");
        } else if (countNativo == K) {
            printf("%s\n", primeiraLingua);
        } else {
            printf("ingles\n");
        }
    }

    return 0;
}
