#ifndef T_UTILIDADES
#define T_UTILIDADES

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

static int ehNumero(char c);

static int ehLetra(char c);

int qtdNumeros(char *entrada);

int qtdLetras(char *entrada);

char *inicializaVetor(int tam);

void preencheVetorNum(char *vetNum, char *entrada);

void preencheVetorLetras(char *vetLetras, char *entrada);

void inicializaEspecificacao(char *especificacao, int t, char *caminho);


#endif