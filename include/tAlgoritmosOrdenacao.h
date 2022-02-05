#ifndef T_ALGORITMOS_ORDENACAO
#define T_ALGORITMOS_ORDENACAO

#include <stdio.h>

#define TRUE 1

void selectionsort(int *vet, int tam, int T, int *comp, int *trocas); //

void insertionsort(int *vet, int tam, int T, int *comp, int *trocas); 

void shellSort(int *vet, int tam, int t,int *comp, int *trocas);

void quickSort(int *vet, int esq, int dir, int *comp, int *trocas, int T); //

void heapSort(int *vet, int n, int T , int *comp,int *trocas);

#endif