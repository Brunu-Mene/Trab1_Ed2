#ifndef T_UTILIDADES
#define T_UTILIDADES

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

typedef struct tVetorOrdenavel tVetorOrdenavel;

/**
* @brief: verifica se o caracter é um caracter numérico;
* @param c: caractere a ser verificado;
* @return: boolean;
*/
static int ehNumero(char c);

/**
* @brief: Verifica se o caracter é uma letra;
* @param c: Caractere a ser verificado;
* @return: Boolean;
*/
int ehLetra(char c);

/**
* @brief: Conta a quantidaded de números que existem em uma string
* @param entrada: A string;
* @return: Inteiro com a quantidade de números;
*/
int qtdNumeros(char *entrada);

/**
* @brief: Conta a quantidade de letras em uma string;
* @param entrada: A tring;
* @return: Inteiro com quantidade de letras;
*/
int qtdLetras(char *entrada);

/**
* @brief: Aloca na memoria heap para um vetor de char;
* @param tam: Inteiro com a quantidade de posições a serem alocadas;
* @return: Ponteiro char com o endereço alocado;
*/
char *inicializaVetorChar(int tam);

/**
* @brief:  Aloca espaço na memória heap para um vetor de inteiros com o tamanho que foi passado;
* @param tam: Tamanho do vetor a ser inicializado;
* @return: Ponteiro inteiro com o endereço alocado;
*/
int* inicializaVetorInt(int tam);

/**
* @brief: Libera da memoria um ponteiro;
* @param vet: Um ponteiro qualquer previamente alocado;
*/
void liberaVetor(void *vet);

/**
* @brief:  Recebe uma string e copia para um vetor de caracteres os caracteres numéricos dessa string;
* @param vetNum: Vetor de caracteres que irá receber os caracteres númericos;
* @param entrada: String que será lida;
*/
void preencheVetorNum(char *vetNum, char *entrada);

/**
* @brief:  Recebe uma string e copia para um vetor de caracteres as letras dessa string;
* @param vetLetras: Vetor de caracteres que irá receber as letras;
* @param entrada: String que será lida;
*/
void preencheVetorLetras(char *vetLetras, char *entrada);

/**
* @brief: Aloca e preenche estrutura para carregar os dados inteiros a serem ordenados;
* @param caminho: Uma string contendo o caminho do arquivo de entrada;
* @return : Um ponteiro com a estrutura auxiliar alocada e preenchida;
*/
tVetorOrdenavel *inicializaEstruturaDoVetor(char *caminho);

/**
* @brief: Libera da memoria a estrutura auxiliar;
* @param tVet: Um ponteiro para uma estrutura alocada;
*/
void liberaEstrutura(tVetorOrdenavel *tVet);

/**
* @brief: Função responsável por analisar a entrada do usuário e a partir dela chamar as funções correspondentes;
* @param tVet: Struct que contém o vetor a ser ordenado junto com um inteiro que representa o tamanho desse vetor;
* @param vetNum: String contendo os comandos de impressão;
* @param vetletras: String contendo a sequência de algorítmos a serem executadois;
* @param t: quantidade top a ser ordenado;
* @param caminho: caminho do arquivo a ser lido;
*/
void inicializaEspecificacao(tVetorOrdenavel *tVet, char *vetNum, char *vetLetras, int t, char *caminho);

/**
* @brief: Função responsável por chamar as funções de imprimir os relatórios;
* @param vet: Vetor de inteiros que irá receber o conteúdo;
* @param tam: Inteiro com o tamanho do vetor de dados;
* @param vetNum: String contendo os comandos de inmpressão;
* @param letra: Letra inicial do algoritmo de ordenação a ser chamado;
* @param caminho: caminho do arquivo a ser lido;
* @param t: quantidade top a ser ordenado;
* @param comp: quantidade de comparações de uma ordenação;
* @param trocas: quantidade de trocas de uma ordenação;
* @param tempo: tempo gasto pela função de ordenação;
*/
void chamaRelatorios(int *vet, int tam, char *vetNum, char letra, char *caminho, int t, unsigned long int comp, unsigned long int trocas,float tempo);

/**
* @brief:  Recebe dois ponteiros de inteiros e copia o conteúdo do ponteiro vetReceb para o ponteiro vetDistr;
* @param vetReceb: Vetor de inteiros que irá receber o conteúdo;
* @param vetDistr: Vetor de inteiros que terá o conteúdo copiado;
* @param tam: O tamanho do vetor a ser copiado;
*/
void transfereConteudo(int *vetReceb, int *vetDistr, int tam);

#endif