#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int Separa(int p, int r, int v[]){
    int c, j, k, t;
    c = v[r]; j = p;

    for (k=p; k<r; k++)
        if (v[k] <= c){
            t = v[j], v[j] = v[k], v[k] = t;
            j++;
        }

    v[r] = v[j], v[j] = c; 
    return j;
}

void Quicksort(int p, int r, int v[]){
    int j;
    if (p<r){
        j = Separa (p, r, v);
        if (j-p < r-j){
         Quicksort (p, j-1, v);
         p = j+1;
        }
        else {
         Quicksort (j+1, r, v);
         r = j-1;
        }
    }
}

int main(){
    int *v = NULL;
    int n = 5000;
    clock_t tIni, tFim;
    double tTotal;

    v = (int *) malloc(n * sizeof(int));

    for (int i=0; i<n; i++){
            v[i] = rand() % n + 5000;
    }

    tIni = clock();
    Quicksort(0, n, v);
    tFim = clock();

    tTotal = ((double)(tFim - tIni)/ CLOCKS_PER_SEC)*1000;
        printf("Tempo total: %f\n", tTotal);
}
