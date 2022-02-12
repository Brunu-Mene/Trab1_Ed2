#include "../include/tRelatorio.h"

void relatorio1(int *vet, int t){
    printf("Top %d elementos do vetor de inteiros:\n", t);
    for(int i = 0; i < t; i++){
        printf("%d\n",vet[i]);
    }
    printf("\n");
}

void relatorio2(float tempo, unsigned long int comp, unsigned long int trocas){
    printf("Estatísticas gerais:\n");
    printf("Tempo de CPU: 	    %.5f segundos.\n",tempo);
    printf("Comparações:	    %lu\n",comp);
    printf("Trocas:             %lu\n\n",trocas); 
}

void relatorio3(char algoritmo, char* arquivo, int tam, int T, unsigned long int comp, unsigned long int trocas, float tempo){
    printf("[algoritmo\tarquivo\t\t\ttam.\tT(top)\tcomp.\ttrocas\ttempo(s)]\n");
    if(algoritmo == 's'){
        printf(" seleção\t");
    }else if(algoritmo == 'i'){
        printf(" inserção\t");
    }else if(algoritmo == 'e'){
        printf(" shellsort\t");
    }else if(algoritmo == 'q'){
        printf(" quicksort\t");
    }else if(algoritmo == 'h' || algoritmo == 'a'){
        printf(" heapsort\t");
    }
    printf("%s\t%d\t%d\t%lu\t%lu\t%.5f\n\n", arquivo, tam, T, comp, trocas, tempo);
}