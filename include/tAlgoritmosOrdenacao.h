#ifndef T_ALGORITMOS_ORDENACAO
#define T_ALGORITMOS_ORDENACAO

#include <stdio.h>

#define TRUE 1

void selectionsort(int *vet, int tam, int T, unsigned long int *comp, unsigned long int *trocas);

void insertionsort(int *vet, int tam, int T, unsigned long int *comp, unsigned long int *trocas); 

void shellSort(int *vet, int tam, int t,unsigned long int *comp, unsigned long int *trocas);

void quickSort(int *vet, int esq, int dir, unsigned long int *comp, unsigned long int *trocas, int T);

void heapSort(int *vet, int n, int T , unsigned long int *comp,unsigned long int *trocas);

#endif