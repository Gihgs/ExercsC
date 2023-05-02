#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void Selecao (int n,int v[]){
    int i, j, min, x;
    for (i=0; i<n-1; i++){
        min = i; 
        for (j=i+1; j<n; j++)
            if (v[j] < v[min]) min = j;
        x = v[i]; v[i] = v[min]; v[min] = x;
    }
}

int main () {
    
    int *v = NULL;
    int n = 5000;
    clock_t tIni, tFim;
    double tTotal;

    v = (int *) malloc(n * sizeof(int));

    for (int i=0; i<n; i++){
            v[i] = rand() % n + 5000;
    }

    tIni = clock();
    Selecao(n, v);
    tFim = clock();

    tTotal = ((double)(tFim - tIni)/ CLOCKS_PER_SEC)*1000;
        printf("Tempo total: %f\n", tTotal);
}