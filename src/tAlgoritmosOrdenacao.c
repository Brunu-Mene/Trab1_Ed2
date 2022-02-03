#include "../include/tAlgoritmosOrdenacao.h"

void selectionsort(int *vet, int tam, int T, int *comp, int *trocas){
    int max, aux, parador = 0;
    for (int i = 0; i < (tam-1); i++){
        if(parador == T){
            break;
        }
        parador++;
        max = i;
        for (int j = (i+1); j < tam; j++){
            if(vet[j] > vet[max]){
                max = j;
                *comp = *comp + 1;
            } 
        }
        if (i != max) {
            aux = vet[i];
            vet[i] = vet[max];
            vet[max] = aux;
            *trocas = *trocas + 1;
        }
    }
}

void insertionsort(int *vet, int tam, int T, int *comp, int *trocas){
    int aux,parador = 0;
    for (int i = 1; i < tam; i++) {
        if(parador == T) break;
        parador++;
        aux = vet[i];
        int j = i - 1;
        while (j >= 0 && vet[j] < aux) {
            vet[j + 1] = vet[j];
            j = j - 1;
            *comp = *comp + 1;
        }
        vet[j + 1] = aux;
        *trocas = *trocas + 1;
    }
}

void shellsort(int* vet, int tam, int T){
    int aux;
    int h = 1;
    while(h < tam) {
        h = 3*h+1;
    }
    while (h > 0) {
        for(int i = h; i < tam; i++) {
            aux = vet[i];
            int j = i;
            while (j > h-1 && aux <= vet[j - h]) {
                vet[j] = vet[j - h];
                j = j - h;
            }
            vet[j] = aux;
        }
        h = h/3;
    }
}

void quicksort(int *vet, int esq, int dir, int T){
    int i, j, x, y;
     
    i = esq;
    j = dir;
    x = vet[(esq + dir) / 2];
    
    while(i <= j) {
        while(vet[i] < x && i < dir) {
            i++;
        }
        while(vet[j] > x && j > esq) {
            j--;
        }
        if(i <= j) {
            y = vet[i];
            vet[i] = vet[j];
            vet[j] = y;
            i++;
            j--;
        }
    }
     
    if(j > esq) {
        quicksort(vet, esq, j, T);
    }
    if(i < dir) {
        quicksort(vet, i, dir, T);
    }
}

void heapsort(int *vet, int n, int T){
    int i = n / 2, pai, filho, t;
    while(TRUE) {
        if (i > 0) {
            i--;
            t = vet[i];
        } else {
            n--;
            if (n <= 0) return;
            t = vet[n];
            vet[n] = vet[0];
        }
        pai = i;
        filho = i * 2 + 1;
        while (filho < n) {
            if ((filho + 1 < n)  &&  (vet[filho + 1] > vet[filho]))
                filho++;
            if (vet[filho] > t) {
                vet[pai] = vet[filho];
                pai = filho;
                filho = pai * 2 + 1;
            } else {
                break;
            }
        }
        vet[pai] = t;
    }
}