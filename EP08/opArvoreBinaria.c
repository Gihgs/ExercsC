/*CÓDIGO INCOMPLETO*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 1000

typedef int TIPOCHAVE;

struct nozinho{
  TIPOCHAVE chave;
  struct nozinho *direita;
  struct nozinho *esquerda;
  char dado;
}; 
typedef struct nozinho no;
typedef no *arvore;


struct nozinho* novoNo(char letra);
void posfixa(struct nozinho *arvore);
int src(char *str, int inicio, int fim, char letra);
struct nozinho* arv(char *infixa, char *prefixa, int inInicio, int inFim);

short indice;

struct nozinho* novoNo(char letra)
{
	struct nozinho *no = (struct nozinho *) malloc(sizeof(struct nozinho));
	no->dado = letra;
	no->esquerda = no->direita = NULL;

	return no;
}

int src(char *str, int inicio, int fim, char letra)
{
	short i;
	for (i = inicio; i <= fim; ++i)
		if (str[i] == letra)
			return i;

	return -1;
}

struct nozinho* arv(char *infixa, char *prefixa, int inInicio, int inFim)
{
	int infixaIndice;

	if (inInicio > inFim)
		return NULL;

	struct nozinho *no = novoNo(prefixa[indice++]);
	if (inInicio == inFim)
		return no;

	infixaIndice = src(infixa, inInicio, inFim, no->dado);
	no->esquerda = arv(infixa, prefixa, inInicio, infixaIndice - 1);
	no->direita = arv(infixa, prefixa, infixaIndice + 1, inFim);

	return no;
}

void posfixa(struct nozinho *no)
{
	if (no == NULL)
		return;

	posfixa(no->esquerda);
	posfixa(no->direita);
	printf("%c", no->dado);
}

no *Busca (arvore r, int k){
    if (r == NULL || r->chave == k)
       return r;
    if (r->chave > k)
        return Busca (r->esquerda, k);
    else
        return Busca (r->direita, k);
}

arvore Insere (arvore r, no *novo) {
    no *f, *p;
    if (r == NULL) return novo;
    f = r;
    while (f != NULL){
        p = f;
        if (f->chave > novo->chave) f= f->esquerda;
        else f = f->direita;
    }
    if (p->chave > novo->chave) p->esquerda = novo;
    else p->direita = novo;
    return r;
}

arvore RemoveRaiz (arvore r) {
    no *p, *q;
    if (r->esquerda == NULL) q = r->direita;
    else {
        p = r; q = r->esquerda;
        while (q->direita != NULL){
            p = q; q = q->direita;
        }

        if (p != r){
            p-> direita = q->esquerda;
            q-> esquerda = r->esquerda;
        }
        q->direita = r->direita;
    }
    free (r);
    return q;
}

void main ()
{
    typedef no *arvore;
    
    char txt, input[1000];
	char ins = "I";
    char pre =  "PREFIXA";
    char inf = "INFIXA";
    char pos = "POSFIXA";
    char b = "P"; 

	scanf("%s", &txt);

    if (tolower(txt) == ins){
        scanf("%s", &input);
        Insere(arvore, input);
    }

    if (tolower(txt) == pre){
    
    
    }


}
