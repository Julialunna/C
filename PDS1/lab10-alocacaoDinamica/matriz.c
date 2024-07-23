#include <stdio.h>
#include <stdlib.h>
#define SUCESSO 0
int main(int argc, char*argv[]){
    int quantLinhas,quantColunas, **matriz, i, j;

    scanf("%d", &quantLinhas);
    scanf("%d", &quantColunas);

    matriz=(int**)malloc(quantLinhas*sizeof(int*));
    for(i=0;i<quantLinhas;i++){
        matriz[i]=(int*)malloc(quantColunas*sizeof(int));
        for(j=0;j<quantColunas;j++){
            scanf("%d", &matriz[i][j]);
        }
    }
    for(i=0;i<quantLinhas;i++){
        for(j=0;j<quantColunas;j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    for(i=9;i<quantLinhas;i++){
        free(matriz[i]);
    }
    return SUCESSO;
}