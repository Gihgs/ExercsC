//CÓDIGO INCOMPLETO
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define maxVertices 1000

//cidades = vértices
//rotas = arestas, 1 rota passa por 2 cidades, contendo 1h


int distanciaMinima (int dist[], bool sptSet[]){
    int min = INT_MAX, min_index;
  
    for (int v = 0; v < maxVertices; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
  
    return min_index;
}

void printaResult(int dist[]){
    for (int i = 0; i < maxVertices; i++)
        printf("%d\n", dist[i]);
}
  

void dijkstra (int vertices, int origem, int destino, int *custos){
    int destino, vertices = 0, origem;
    int i, v, cont = 0;
    int *ant, *tmp;
    int *z; //caminho mínimo conhecido
    double min;
    double dist[vertices]; //custos dos caminhos

    ant = calloc (vertices, sizeof(int *));
    tmp = calloc (vertices, sizeof(int *));

    z = calloc (vertices, sizeof(int *));

}
    

int main (){
    int Ncid, Nrotas, A, B, C, E, R;
    
    scanf ("%i", &Ncid);
    scanf ("%i", &Nrotas);

    
}

