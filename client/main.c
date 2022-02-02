#include <stdio.h>
#include "../include/tAlgoritmosOrdenacao.h"
#include "../include/tUtilidades.h"

int main(int argv, char **args){
    if(argv < 4){
        printf("Parametros incorretos!\n");
        return 0;
    }

    char *vetNum, *vetLetras;
    vetNum = inicializaVetor(qtdNumeros(args[1]));
    vetLetras = inicializaVetor(qtdLetras(args[1]));
    preencheVetorLetras(vetLetras,args[1]);
    preencheVetorNum(vetNum,args[1]);

    printf("\nNumeros: %s\nLetras: %s\n\n", vetNum,vetLetras);

    return 0;
}