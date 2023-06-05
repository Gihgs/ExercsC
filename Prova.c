#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int chave;
    struct No* esq;
    struct No* dir;
} No;

No* criaNo(int chave) {
    No* novo = (No*)malloc(sizeof(No));
    novo->chave = chave;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

No* insereArv(No* raiz, int chave) {
    if (raiz == NULL)
        return criaNo(chave);

    if (chave < raiz->chave)
        raiz->esq = insereArv(raiz->esq, chave);
    else
        raiz->dir = insereArv(raiz->dir, chave);

    return raiz;
}

void preOrdem(No* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->chave);
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);
    }
}

void emOrdem(No* raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esq);
        printf("%d ", raiz->chave);
        emOrdem(raiz->dir);
    }
}

void posOrdem(No* raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->esq);
        posOrdem(raiz->dir);
        printf("%d ", raiz->chave);
    }
}



int main() {
    int nteste;
    scanf("%d", &nteste);

    for (int caso = 1; caso <= nteste; caso++) {
        int num;
        scanf("%d", &num);

        No* raiz = NULL;
        for (int i = 0; i < num; i++) {
            int num;
            scanf("%d", &num);
            raiz = insereArv(raiz, num);
        }

        printf("Case %d:\n", caso);
        printf("Pre.: ");
        preOrdem(raiz);
        printf("\n");

        printf("In..: ");
        emOrdem(raiz);
        printf("\n");

        printf("Post: ");
        posOrdem(raiz);
        printf("\n");

        printf("\n");


    }

    return 0;
}
