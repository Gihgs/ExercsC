#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 201
#define MAX_DICTIONARY_SIZE 5000

typedef struct {
    char palavra[MAX_LINE_LENGTH];
} Entrada;

void merge(Entrada* dicionario, Entrada* temp, int esquerda, int meio, int direita) {
    int i = esquerda;
    int j = meio + 1;
    int k = esquerda;

    while (i <= meio && j <= direita) {
        if (strcmp(dicionario[i].palavra, dicionario[j].palavra) <= 0)
            strcpy(temp[k++].palavra, dicionario[i++].palavra);
        else
            strcpy(temp[k++].palavra, dicionario[j++].palavra);
    }

    while (i <= meio)
        strcpy(temp[k++].palavra, dicionario[i++].palavra);

    while (j <= direita)
        strcpy(temp[k++].palavra, dicionario[j++].palavra);

    for (int indice = esquerda; indice <= direita; indice++)
        strcpy(dicionario[indice].palavra, temp[indice].palavra);
}

void mergeSort(Entrada* dicionario, Entrada* temp, int esquerda, int direita) {
    if (esquerda < direita) {
        int meio = (esquerda + direita) / 2;
        mergeSort(dicionario, temp, esquerda, meio);
        mergeSort(dicionario, temp, meio + 1, direita);
        merge(dicionario, temp, esquerda, meio, direita);
    }
}

bool ehDuplicado(const char* palavra, Entrada* dicionario, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (strcmp(dicionario[i].palavra, palavra) == 0)
            return true;
    }
    return false;
}

int main() {
    Entrada dicionario[MAX_DICTIONARY_SIZE];
    Entrada temp[MAX_DICTIONARY_SIZE];
    int tamanhoDicionario = 0;

    char linha[MAX_LINE_LENGTH];

    while (scanf(" %[^\n]", linha) != EOF) {
        int i = 0;
        int j = 0;

        while (linha[i]) {
            if (isalpha(linha[i])) {
                dicionario[tamanhoDicionario].palavra[j++] = tolower(linha[i++]);
            } else {
                if (j > 0) {
                    dicionario[tamanhoDicionario].palavra[j] = '\0';
                    if (!ehDuplicado(dicionario[tamanhoDicionario].palavra, dicionario, tamanhoDicionario))
                        tamanhoDicionario++;
                }
                i++;
                j = 0;
            }
        }

        if (j > 0) {
            dicionario[tamanhoDicionario].palavra[j] = '\0';
            if (!ehDuplicado(dicionario[tamanhoDicionario].palavra, dicionario, tamanhoDicionario))
                tamanhoDicionario++;
        }
    }

    mergeSort(dicionario, temp, 0, tamanhoDicionario - 1);

    for (int i = 0; i < tamanhoDicionario; i++)
        printf("%s\n", dicionario[i].palavra);

    return 0;
}
