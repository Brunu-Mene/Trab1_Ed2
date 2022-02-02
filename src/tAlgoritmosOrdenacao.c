#include "../include/tAlgoritmosOrdenacao.h"

void selectionsort(int *vet, int tam){
    int min, aux;
    for (int i = 0; i < (tam-1); i++){
        min = i;
        for (int j = (i+1); j < tam; j++){
            if(vet[j] < vet[min]) 
                min = j;
        }
        if (i != min) {
            aux = vet[i];
            vet[i] = vet[min];
            vet[min] = aux;
        }
    }
}

void insertionsort(int *vet, int tam){
    int aux;
    for (int i = 1; i < tam; i++) {
        aux = vet[i];
        int j = i - 1;
        while (j >= 0 && vet[j] > aux) {
            vet[j + 1] = vet[j];
            j = j - 1;
        }
        vet[j + 1] = aux;
    }
}

void shellsort(int* vet, int tam){
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

void quicksort(int *vet, int esq, int dir){
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
        quicksort(vet, esq, j);
    }
    if(i < dir) {
        quicksort(vet, i, dir);
    }
}

void heapsort(int *vet, int n){
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