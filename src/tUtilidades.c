#include "../include/tUtilidades.h"
#include "../include/tAlgoritmosOrdenacao.h"
#include "../include/tRelatorio.h"


struct tVetorOrdenavel{
    int *vet;
    int tam;
};

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

char *inicializaVetorChar(int tam){
    char *vet = (char *) calloc(tam+1,sizeof(char));
    if(vet == NULL){
        printf("Erro na alocação do vetor de char!\n");
        exit(1);
    }
    return vet;
}

int* inicializaVetorInt(int tam){
    int *vet = (int *) malloc(sizeof(int)*tam);
    if(vet == NULL){
        printf("Erro na alocação do vetor de int!\n");
        exit(1);
    }
    return vet;
}

void liberaVetor(void *vet){
    free(vet);
}

void preencheVetorNum(char *vetNum, char *entrada){
    int j = 0;
    for(int i=0; i<strlen(entrada) ;i++){
        if(ehNumero(entrada[i]) == TRUE){
            vetNum[j] = entrada[i];
            j++;
        }
    }
    vetNum[j] = '\0';
}

void preencheVetorLetras(char *vetLetras, char *entrada){
    int j = 0;
    for(int i=0; i < strlen(entrada); i++){
        if(ehLetra(entrada[i]) == TRUE){
            vetLetras[j] = entrada[i];
            j++;
        }
    }
    vetLetras[j] = '\0';
}

tVetorOrdenavel *inicializaEstruturaDoVetor(char *caminho){
    tVetorOrdenavel *tVetor = malloc(sizeof(tVetorOrdenavel));
    FILE *arq = fopen(caminho,"r");
    if(arq == NULL){
        printf("Erro na abertura do arquivo de entrada!\n");
        exit(1);
    }
    fscanf(arq,"%d",&tVetor->tam);
    tVetor->vet = inicializaVetorInt(tVetor->tam);
    for(int i = 0; i < tVetor->tam; i++){
        fscanf(arq,"%d",&tVetor->vet[i]);
    }
    fclose(arq);

    return tVetor;
}

void liberaEstrutura(tVetorOrdenavel *tVet){
    free(tVet->vet);
    free(tVet);
}


//como fica isso daqui
void inicializaEspecificacao(tVetorOrdenavel *tVet, char *vetNum, char *vetLetras, int t, char *caminho){
    int *vetAux = inicializaVetorInt(tVet->tam);
    transfereConteudo(vetAux, tVet->vet, tVet->tam);

    unsigned long int trocas, comp;
    for(int i=0; i < strlen(vetLetras) ;i++){
        clock_t t_init,t_final;
        trocas = comp = 0;
        t_init = clock();
        switch (vetLetras[i]){
            case 'a':
                selectionsort(tVet->vet,tVet->tam,t,&comp,&trocas);
                t_final = clock();
                chamaRelatorios(tVet->vet,tVet->tam,vetNum,'s',caminho,t,comp,trocas,(float)(t_final - t_init)/1000000);
                transfereConteudo(tVet->vet, vetAux, tVet->tam);
                trocas = comp = 0;

                t_init = clock();
                insertionsort(tVet->vet,tVet->tam,t,&comp,&trocas);
                t_final = clock();
                chamaRelatorios(tVet->vet,tVet->tam,vetNum,'i',caminho,t,comp,trocas,(float)(t_final - t_init)/1000000);
                transfereConteudo(tVet->vet, vetAux, tVet->tam);
                trocas = comp = 0;

                t_init = clock();
                shellSort(tVet->vet,tVet->tam,t,&comp,&trocas);
                t_final = clock();
                chamaRelatorios(tVet->vet,tVet->tam,vetNum,'e',caminho,t,comp,trocas,(float)(t_final - t_init)/1000000);
                transfereConteudo(tVet->vet, vetAux, tVet->tam);
                trocas = comp = 0;

                t_init = clock();
                quickSort(tVet->vet,0,tVet->tam-1,&comp,&trocas,t);
                t_final = clock();
                chamaRelatorios(tVet->vet,tVet->tam,vetNum,'q',caminho,t,comp,trocas,(float)(t_final - t_init)/1000000);
                transfereConteudo(tVet->vet, vetAux, tVet->tam);
                trocas = comp = 0;

                t_init = clock();
                heapSort(tVet->vet,tVet->tam,t,&comp,&trocas);
                break;
            case 's':
                selectionsort(tVet->vet,tVet->tam,t,&comp,&trocas);
                break;
            case 'i':
                insertionsort(tVet->vet,tVet->tam,t,&comp,&trocas);
                break;
            case 'e':
                shellSort(tVet->vet,tVet->tam,t,&comp,&trocas);
                break;
            case 'q':
                quickSort(tVet->vet,0,tVet->tam-1,&comp,&trocas,t);
                break;
            case 'h':
                heapSort(tVet->vet,tVet->tam,t,&comp,&trocas);
                break;
            default:
                break;
        }
        t_final = clock();
        chamaRelatorios(tVet->vet,tVet->tam,vetNum,vetLetras[i],caminho,t,comp,trocas,(float)(t_final - t_init)/1000000);
        transfereConteudo(tVet->vet, vetAux, tVet->tam);
    }
    liberaVetor(vetAux);
}

void chamaRelatorios(int *vet, int tam, char *vetNum, char letra, char *caminho, int t, unsigned long int comp, unsigned long int trocas,float tempo){
    for(int j=0; j<strlen(vetNum) ;j++){
        switch (vetNum[j]){
            case '1':
                relatorio1(vet,t);
                break;
            case '2':
                relatorio2(tempo,comp,trocas);
                break;
            case '3':
                relatorio3(letra,caminho,tam,t,comp,trocas,tempo);
                break;

            default:
                break;
        }
    }
}

void transfereConteudo(int *vetReceb, int *vetDistr, int tam){
    for(int i=0; i<tam ;i++){
        vetReceb[i] = vetDistr[i];
    }
}

int ehNumero(char c){
    if(c > '0' && c <= '3') 
        return TRUE;
    return FALSE;
}

int ehLetra(char c){
    if((c >= 'a' && c <= 'z') || (c >='A' && c <='Z')) 
        return TRUE;
    return FALSE;
}

