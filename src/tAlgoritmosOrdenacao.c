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
                (*comp)++;
            } 
        }
        if (i != max) {
            aux = vet[i];
            vet[i] = vet[max];
            vet[max] = aux;
            (*trocas)++;
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
            (*comp)++;
        }
        vet[j + 1] = aux;
        (*comp)++;
        (*trocas)++;
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

void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high, int *comp, int *trocas){
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high- 1; j++){
        if (arr[j] >= pivot){
            (*comp)++;
            i++;
            swap(&arr[i], &arr[j]);
            (*trocas)++;
        }
    }
    swap(&arr[i + 1], &arr[high]);
    (*trocas)++;

    return (i + 1);
}


void quickSort(int *vet, int esq, int dir, int *comp, int *trocas ,int T){
    if (esq < dir){
        (*comp)++;
        int pi = partition(vet, esq, dir, comp, trocas);
        quickSort(vet, esq, pi - 1, comp, trocas, T);
        if(pi < T-1)
            quickSort(vet, pi + 1, dir, comp, trocas, T);
    }
}

// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
 
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
 
// main function to do heap sort
void heapSort(int arr[], int n, int T)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    // One by one extract an element from heap
    for (int i = n - 1; i >= n - T; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);
 
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}