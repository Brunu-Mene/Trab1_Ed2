#ifndef T_ALGORITMOS_ORDENACAO
#define T_ALGORITMOS_ORDENACAO

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1

void selectionsort(int *vet, int tam);

void insertionsort(int *vet, int tam);

void shellsort(int* vet, int tam);

void quicksort(int *vet, int esq, int dir);

void heapsort(int *vet, int n);

#endif