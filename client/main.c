#include <stdio.h>
#include "../include/tAlgoritmosOrdenacao.h"
#include "../include/tUtilidades.h"

int main(int argv, char **args){
    if(argv < 4){
        printf("Parametros incorretos!\n");
        return 0;
    }
    tVetorOrdenavel *vetInt = inicializaEstruturaDoVetor(args[3]);
    char *vetNum, *vetLetras;
    vetNum = inicializaVetorChar(qtdNumeros(args[1]));
    vetLetras = inicializaVetorChar(qtdLetras(args[1]));
    preencheVetorLetras(vetLetras,args[1]);
    preencheVetorNum(vetNum,args[1]);

    liberaVetor(vetLetras);
    liberaVetor(vetNum);
    liberaEstrutura(vetInt);
    return 0;
}