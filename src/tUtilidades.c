#include "../include/tUtilidades.h"

int qtdNumeros(char *entrada){
    int qtdNumeros = 0;
    for(int i = 0; i < strlen(entrada); i++){
        if(ehNumero(entrada[i]) == TRUE)
            qtdNumeros++; 
    }
    return qtdNumeros;
}

int qtdLetras(char *entrada){
    int qtdLetras = 0;
    for(int i=0; i < strlen(entrada);i++){
        if(ehLetra(entrada[i]) == TRUE)
            qtdLetras++;
    }
    return qtdLetras;
}

char *inicializaVetor(int tam){
    char *vet = (char *) malloc(sizeof(char)*tam);
    if(vet == NULL){
        printf("Erro na alocação do vetor de char!\n");
        exit(1);
    }
    return vet;
}

void preencheVetorNum(char *vetNum, char *entrada){
    int j = 0;
    for(int i=0; i<strlen(entrada) ;i++){
        if(ehNumero(entrada[i]) == TRUE){
            vetNum[j] = entrada[i];
            j++;
        }
    }
}

void preencheVetorLetras(char *vetLetras, char *entrada){
    int j = 0;
    for(int i=0; i<strlen(entrada) ;i++){
        if(ehLetra(entrada[i]) == TRUE){
            vetLetras[j] = entrada[i];
            j++;
        }
    }
}

void inicializaEspecificacao(char *especificacao, int t, char *caminho){
    
}

static int ehNumero(char c){
    if(c > '0' && c <= '3') 
        return TRUE;
    return FALSE;
}

static int ehLetra(char c){
    if((c >= 'a' && c <= 'z') || (c >='A' && c <='Z')) 
        return TRUE;
    return FALSE;
}

