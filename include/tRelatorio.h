#ifndef T_RELATORIO
#define T_RELATORIO

#include <stdio.h>

/**
* @brief: Função para imprimir em tela os T maiores elementos
* @param vet: vetor contendo os dados inteiros pós ordenação;
* @param t: limitador de top elementos a serem exibidos;
*/
void relatorio1(int *vet, int t);

/**
* @brief: Função para imprimir estatísticas: 
* @param tempo: Float correspondente ao tempo gasto na execução dos algoritmos.
* @param comp: Inteiro com a quantidade de comparações;
* @param trocas: Inteiro com a quantidade de trocas;;
*/
void relatorio2(float tempo, long long int comp, long long int trocas);

/**
* @brief: Função para imprimir dados/estatísticas separados por tab;
* @param algoritmo: letra inicial do algoritmo de ordenação;
* @param arquivo: nome do arquivo que foi lido;
* @param tam: tamanho do vetor que foi ordenado;
* @param T: quantidade top que foi ordenada;
* @param comp: quantidade de comparações de uma ordenação;
* @param trocas: quantidade de trocas de uma ordenação;
* @param tempo: tempo gasto pela função de ordenação;
*/
void relatorio3(char algoritmo, char* arquivo, int tam, int T, long long int comp, long long int trocas, float tempo);


#endif