#include "../include/tAlgoritmosOrdenacao.h"

void swap(int* a, int* b, int *trocas){
    int t = *a;
    *a = *b;
    *b = t;
    (*trocas)++;
}

int partition (int arr[], int low, int high, int *comp, int *trocas){
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high- 1; j++){
        if (arr[j] >= pivot){
            i++;
            swap(&arr[i], &arr[j], trocas);
        }
        (*comp)++;
    }
    swap(&arr[i + 1], &arr[high], trocas);

    return (i + 1);
}

// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int *vet, int n, int i, int *comp,int *trocas)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && vet[l] > vet[largest]){
        largest = l;
    }
 
    // If right child is larger than largest so far
    if (r < n && vet[r] > vet[largest]){
        largest = r;
    }
 
    // If largest is not root
    (*comp) += 3;
    if (largest != i) {
        swap(&vet[i], &vet[largest], trocas);
 
        // Recursively heapify the affected sub-tree
        heapify(vet, n, largest, comp, trocas);
    }
}

void selectionsort(int *vet, int tam, int T, int *comp, int *trocas){
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

void insertionsort(int *vet, int tam, int T, int *comp, int *trocas){
    int i, j, k;
    for (i = 0; i < T; i++){ 
        int min = i;
        for (j = i+1; j < tam; j++){
            if (vet[j] > vet[min]){
                min = j;
            }
            (*comp)++;
        }
        k = vet[min];
        for (j = min; j > i; j--){
            vet[j] = vet[j-1];
            (*trocas)++;
        }
        vet[i] = k;
        (*trocas)++;
    }
}

void shellsort(int* vet, int tam, int T, int *comp, int *trocas){
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
                (*comp)++;
                (*trocas)++;
            }
            vet[j] = aux;
            (*trocas)++;
        }
        h = h/3;
    }
}

//o somatorio de comp e trocas ta errado!!! (ou nao)
void quickSort(int *vet, int esq, int dir, int *comp, int *trocas ,int T){
    if (esq < dir){
        int pi = partition(vet, esq, dir, comp, trocas);
        quickSort(vet, esq, pi - 1, comp, trocas, T);
        if(pi < T-1)
            quickSort(vet, pi + 1, dir, comp, trocas, T);
    }
}
 
// main function to do heap sort
void heapSort(int *vet, int n, int T, int *comp, int *trocas){
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(vet, n, i, comp, trocas);
 
    // One by one extract an element from heap
    for (int i = n - 1; i >= n - T; i--) {
        // Move current root to end
        swap(&vet[0], &vet[i], trocas);
 
        // call max heapify on the reduced heap
        heapify(vet, i, 0, comp, trocas);
    }
}