#include <stdio.h>
#include <stdlib.h>

#define SUCESSO 0
#define TAMANHO_MATRIZ 5
#define TAMANHO_MAX_NOME 100

int main(int argc, char** argv[]) {
    FILE *arquivoEntrada;
    unsigned int matrizEntrada1[TAMANHO_MATRIZ][TAMANHO_MATRIZ], matrizEntrada2[TAMANHO_MATRIZ][TAMANHO_MATRIZ], i, j, escrito=0;
    
    char nomeArquivo[TAMANHO_MAX_NOME];

    scanf("%s", nomeArquivo);
    arquivoEntrada = fopen(nomeArquivo, "r");
    if (arquivoEntrada == NULL) {
       
        exit(1);
    }
 

    for (i = 0; i < TAMANHO_MATRIZ; i++) {
         for (j = 0; j < TAMANHO_MATRIZ; j++) {
           fscanf(arquivoEntrada, "%d", &matrizEntrada1[i][j]);
        }
        
    }
     for (i = 0; i < TAMANHO_MATRIZ; i++) {
        for (j = 0; j < TAMANHO_MATRIZ; j++) {
           fscanf(arquivoEntrada, "%d", &matrizEntrada2[i][j]);
        }
    }

    fclose(arquivoEntrada);

    for (i = 0; i < TAMANHO_MATRIZ; i++) {
        for (j = 0; j < TAMANHO_MATRIZ; j++) {
            printf("%u ", matrizEntrada1[i][j]+matrizEntrada2[i][j]);
        }
        printf("\n");
    }
     


    return SUCESSO;
}
