#include <stdio.h>
#include <stdlib.h>
#define SUCESSO 0
#define TAMANHO_MATRIZ 5
#define TAMANHO_MAX_NOME 100
int main(int argc, char**argv[]){
    FILE *arquivoEntrada;
    int matrizEntrada[TAMANHO_MATRIZ][TAMANHO_MATRIZ], indice=0, i=0,j=0, matrizParaArquivo[TAMANHO_MATRIZ][TAMANHO_MATRIZ], escrito=0;
    char nomeArquivo[TAMANHO_MAX_NOME];


    scanf("%s", nomeArquivo);
    arquivoEntrada=fopen(nomeArquivo, "r");
    if(arquivoEntrada==NULL){
        //printf("Erro na abertura do arquivo");
        exit(1);
    }
    /*for(i=0;i<5;i++){
        printf("a");
        scanf("%d %d %d %d %d", matrizParaArquivo[i]);

    }
    fwrite(matrizParaArquivo, sizeof(int),   5*5, arquivoEntrada);*/

    //rewind(arquivoEntrada);
    while(1){

        fread(matrizEntrada[indice], sizeof(int), 5, arquivoEntrada);
        printf("aa%d\n", matrizEntrada[indice][indice]);
        //printf("%c", letraArquivo);
        if(feof(arquivoEntrada)){
            break;
        }
        indice++;
    }
    for(indice=0;indice<5;indice++){
        for(j=0;j<5;j++){
            printf("%d", matrizEntrada[indice][j]);
        }
        printf("\n");
    }
    return SUCESSO;
}