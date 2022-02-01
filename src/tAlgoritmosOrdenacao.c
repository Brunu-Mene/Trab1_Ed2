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
    for (int i = 1; i < size; i++) {
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

void quicksort(){

}

void heapsort(){
    
}