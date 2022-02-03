#ifndef T_ALGORITMOS_ORDENACAO
#define T_ALGORITMOS_ORDENACAO

#include <stdio.h>

#define TRUE 1

void selectionsort(int *vet, int tam, int T, int *comp, int *trocas);

void insertionsort(int *vet, int tam, int T, int *comp, int *trocas);

void shellsort(int* vet, int tam, int T);

void quicksort(int *vet, int esq, int dir, int T);

void heapsort(int *vet, int n, int T);

#endif