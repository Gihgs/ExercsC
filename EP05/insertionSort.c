#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void Insercao (int n, int v[]) {
    int i, j, x;
    for (j=1; j<n; j++) {
        x = v[j];
        for (i=j-1; i>=0 && v[i]>x; i--)
            v[i+1] = v[i];
    v[i+1] = x;   
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
    Insercao(n, v);
    tFim = clock();

    tTotal = ((double)(tFim - tIni)/ CLOCKS_PER_SEC)*1000;
        printf("Tempo total: %f\n", tTotal);
}