#ifndef T_UTILIDADES
#define T_UTILIDADES

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

typedef struct tVetorOrdenavel tVetorOrdenavel;

static int ehNumero(char c);

static int ehLetra(char c);

int qtdNumeros(char *entrada);

int qtdLetras(char *entrada);

char *inicializaVetorChar(int tam);

static int* inicializaVetorInt(int tam);

void liberaVetor(void *vet);

void preencheVetorNum(char *vetNum, char *entrada);

void preencheVetorLetras(char *vetLetras, char *entrada);

tVetorOrdenavel *inicializaEstruturaDoVetor(char *caminho);

void liberaEstrutura(tVetorOrdenavel *tVet);

void inicializaEspecificacao(tVetorOrdenavel *tVet, char *vetNum, char *vetLetras, int t, char *caminho);

int* inicializaVetorInt(int tam);

static void transfereConteudo(int *vetReceb, int *vetDistr, int tam);

#endif