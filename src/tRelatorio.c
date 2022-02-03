#include "../include/tRelatorio.h"

void relatorio1(int *vet, int t){
    printf("Top %d elementos do vetor de inteiros:\n", t);
    for(int i = 0; i < t; i++){
        printf("%d\n",vet[i]);
    }
    printf("\n");
}

void relatorio2(float tempo, int comp, int trocas){
    printf("Estatísticas gerais:\n");
    printf("Tempo de CPU: 	    %.4f segundos.\n",tempo);
    printf("Comparações:	    %d\n",comp);
    printf("Trocas:             %d\n\n",trocas); 
}

void relatorio3(char algoritmo, char* arquivo, int tam, int T, int comp, int trocas, float tempo){
    printf("[algoritmo  arquivo	tam.	T(top)	comp. 	trocas	tempo(s)]\n");
    if(algoritmo == 'a'){
        printf("todos");
    }else if(algoritmo == 's'){
        printf("seleção");
    }else if(algoritmo == 'i'){
        printf("inserção");
    }else if(algoritmo == 'e'){
        printf("shellsort");
    }else if(algoritmo == 'q'){
        printf("quicksort");
    }else if(algoritmo == 'h'){
        printf("heapsort");
    }
    printf("  %s  %d    %d      %d        %d      %.5f\n\n", arquivo, tam, T, comp, trocas, tempo);
}