//Beecrowd 1195 - Binary Search Tree

#include <stdio.h>
#include <stdlib.h>

typedef int TIPOCHAVE;

struct nozinho{
  TIPOCHAVE chave;
  struct nozinho *direita;
  struct nozinho *esquerda;
  char dado;
};
typedef struct nozinho noh;

typedef noh* PONT;

noh* novoNo(char dado);
void posfixa(noh *arvore);
int src(char *str, int inicio, int fim, char dado);
noh* arv(char *infixa, char *prefixa, int inInicio, int inFim);
int indice;

PONT inicializaArvore();
PONT adicionaArvore(PONT,PONT);
PONT buscaArvore(TIPOCHAVE,PONT);
PONT apagaNo(PONT,TIPOCHAVE);
void imprimirArvore(PONT);
void imprimeArvorePreOrdem(PONT,PONT);
void imprimeArvoreEmOrdem(PONT,PONT);
void imprimeArvorePosOrdem(PONT,PONT);
int contaNos(PONT);

PONT inicializaArvore(){
  return(NULL);
}
PONT criaNo(TIPOCHAVE ch){
  PONT novoNo = (PONT)malloc(sizeof(noh));
  novoNo->esquerda = NULL;
  novoNo->direita = NULL;
  novoNo->chave = ch;
  return(novoNo);
}

PONT adicionaArvore(PONT raiz, PONT no){
  if(raiz == NULL) return(no);
  if(no-> chave < raiz-> chave)
    raiz->esquerda = adicionaArvore(raiz->esquerda, no); 
  else
    raiz->direita = adicionaArvore(raiz->direita,no);
  return(raiz);
}

PONT buscaArvore(TIPOCHAVE ch, PONT raiz){
  if (raiz == NULL) return(NULL);
  if(raiz->chave == ch) return(raiz);
  if(raiz->chave > ch)
    return (buscaArvore(ch, raiz->esquerda));
  return(buscaArvore(ch, raiz->direita));
}

void imprimirArvore(PONT raiz){
  if(raiz!=NULL){
    printf("%i", raiz->chave);
    printf("(");
    imprimirArvore(raiz->esquerda);
    imprimirArvore(raiz->direita);
    printf(")");
  }
}

int contaNos(PONT raiz){
  if(raiz==NULL) return 0;
  return(contaNos(raiz->esquerda)
    +1
    +contaNos(raiz->direita));
}

PONT apagaNo (PONT raiz, TIPOCHAVE ch){
  PONT pai, no, p, q;
  no = buscaArvore(ch,pai);
  if(no == NULL) return(raiz);
  if(!no->esquerda || !no->direita){
    if(!no->esquerda) q = no->direita;
  else
      q = no->esquerda;
  }
  else {
    p = no;
    q = no-> esquerda;
    while(q->direita){
      p=q;
      q=q->direita;
    }
  if(p!=no){
    q->esquerda = no->esquerda;
     p->direita = q->esquerda;
  }
    q->direita = no->direita;    
  }
  if (!pai){
    free(no);
    return(q);
  }
  if(ch<pai->chave)
    pai->esquerda =q;
  else
    pai->direita=q;
  free(no);
  return(raiz);
}

int src(char *str, int inicio, int fim, char letra)
{
	short i;
	for (i = inicio; i <= fim; ++i)
		if (str[i] == letra)
			return i;

	return -1;
}


//funções exercício ----------------------------------------
//Pré-Ordem: RED = raiz, esquerda, direita
//In-Ordem: ERD = esquerda, raiz, direita
//Pós-Ordem: EDR = esquerda, direita, raiz

struct nozinho* arv(char *infixa, char *prefixa, int inInicio, int inFim)
{
	int infixaIndice;

	if (inInicio > inFim)
		return NULL;

	struct nozinho *no = novoNo(prefixa[indice++]);
	if (inInicio == inFim)
		return no;

	infixaIndice = src(infixa, inInicio, inFim, novoNo->dado);
	no->esquerda = arv(infixa, prefixa, inInicio, infixaIndice - 1);
	no->direita = arv(infixa, prefixa, infixaIndice + 1, inFim);

	return no;
  
void posfixa(noh *arvore){

	if (novoNo == NULL)
		return;

	posfixa(novoNo->esquerda);
	posfixa(novoNo->direita);
	printf("%c", novoNo->dado);

}
 
struct noh* criaNo(chave) {
  struct noh* novoNo = malloc(sizeof(struct no));
  novoNo->chave = value; 
  novoNo->esquerda = NULL;
  novoNo->direita = NULL; 
  return novoNo;
}

  }

#define tam 1000
#define tam2 500

int main() {
  int qtsCasos;
	int qtsNodes, i;
	char prefixa[tam], infixa[tam2];

	scanf("%i", &qtsCasos);

	for(i=0;i>=qtsCasos;i++){
		scanf("%i %s %s%*c", &qtsNodes, prefixa, infixa);
		indice = 0;
		struct nozinho *raiz = arv(infixa, prefixa, 0, qtsNodes - 1);
    printf("Case %i",i);
		posfixa(raiz);
		printf("\n");
    
	}
}
