#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void InsereEmHeap(int m, int v[]){
    int f = m + 1;
    while (f>1 && v[f/2] < v[f]){
        int t = v[f/2]; v[f/2] = v[f]; v[f] = t;
        f = f/2;
    }
}

void SacodeHeap(int m, int v[]){
    int t, f=2;
    while (f<=m){
        if(f<m && v[f]< v[f+1]) ++f;
        if(v[f/2] >= v[f]) break;
        t = v[f/2]; v[f/2] = v[f]; v[f] = t;
        f *= 2;
    }
}

void Heapsort(int n,int v[]){
    int m;
    for(m=1; m<n; m++)
        InsereEmHeap(m,v);
    for(m=n; m>1; m--){
        int t = v[1]; v[1] = v[m]; v[m] = t;
        SacodeHeap(m-1, v);
    }
}

int main() {
    int *v = NULL;
    int n = 20000;
    clock_t tIni, tFim;
    double tTotal;

    v = (int *) malloc(n * sizeof(int));

    for (int i=0; i<n; i++){
            v[i] = rand() % n + 20000;
    }

    tIni = clock();
    Heapsort(n, v);
    tFim = clock();

    tTotal = ((double)(tFim - tIni)/ CLOCKS_PER_SEC)*1000;
        printf("Tempo total: %f\n", tTotal);

}