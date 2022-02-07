#include "../include/tAlgoritmosOrdenacao.h"

void swap(int* a, int* b, unsigned long int *trocas){
    int t = *a;
    *a = *b;
    *b = t;
    (*trocas)++;
}

int partition (int *vet, int low, int high, unsigned long int *comp, unsigned long int *trocas){
    int pivot = vet[high];
    int i = (low - 1);
    for (int j = low; j <= high- 1; j++){
        if (vet[j] >= pivot){
            i++;
            swap(&vet[i], &vet[j], trocas);
        }
        (*comp)++;
    }
    swap(&vet[i + 1], &vet[high], trocas);

    return (i + 1);
}

void heapify(int *vet, int n, int i, unsigned long int *comp, unsigned long int *trocas){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < n && vet[left] > vet[largest])
        largest = left;
  
    if (right < n && vet[right] > vet[largest])
        largest = right;
  
    (*comp)+=2;
    if (largest != i){
        swap(&vet[i], &vet[largest],trocas);
        heapify(vet, n, largest,comp,trocas);
    }
}

void selectionsort(int *vet, int tam, int T, unsigned long int *comp, unsigned long int *trocas){
    int max, aux, parador = 0;
    for (int i = 0; i < (tam-1); i++){
        if(parador == T) break;
        max = i;
        for (int j = (i+1); j < tam; j++){
            if(vet[j] > vet[max]){
                max = j;
            } 
            (*comp)++;
        }
        if (i != max) {
            parador++;
            swap(&vet[i],&vet[max],trocas);
        }
    }
}

void insertionsort(int *vet, int tam, int T, unsigned long int *comp, unsigned long int *trocas){
    int i, j, k;
    for (i = 0; i < T; i++){ 
        int min = i;
        for (j = i+1; j < tam; j++){
            if (vet[j] > vet[min]){
                min = j;
            }
            (*comp)++;
        }
        (*comp)++;
        k = vet[min];
        for (j = min; j > i; j--){
            vet[j] = vet[j-1];
        }
        vet[i] = k;
        (*trocas)++;
    }
}


void shellSort(int *vet, int tam, int t, unsigned long int *comp, unsigned long int *trocas){
    int i , j , value;
    int gap = 1;
    
    do {
        gap = 3*gap+1;
    } while(gap < tam);
    
    do {
        gap /= 3;
        for(i = gap; i < tam; i++) {
            value = vet[i];
            j = i - gap;
                
            while (j >= 0 && value > vet[j]) {
                (*comp)++;
                vet[j + gap] = vet[j];
                j -= gap;
            }
            (*comp)++;
            (*trocas)++;
            vet[j + gap] = value;
        }
    }while(gap > 1);
}

void quickSort(int *vet, int esq, int dir, unsigned long int *comp, unsigned long int *trocas ,int T){
    if (esq < dir){
        int pi = partition(vet, esq, dir, comp, trocas);
        quickSort(vet, esq, pi - 1, comp, trocas, T);
        if(pi < T-1)
            quickSort(vet, pi + 1, dir, comp, trocas, T);
    }
}

void heapSort(int *vet, int n, int T , unsigned long int *comp, unsigned long int *trocas) {
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(vet, n, i, comp,trocas);
    for (int i = n - 1; i >= n - T; i--) {
        swap(&vet[0], &vet[i], trocas);
        heapify(vet, i, 0, comp,trocas);
    }
    for(int i = n - 1, j = 0; i >= n - T; i--, j++){
        if(i < n/2){
            break;
        }
        swap(&vet[j],&vet[i],trocas);
    }
}