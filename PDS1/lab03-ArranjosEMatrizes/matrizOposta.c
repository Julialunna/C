#include <stdio.h>
#define SUCESSO 0
#define TAMANHO_MAX_LINHAS 10
#define TAMANHO_MAX_COLUNAS  10

int main(int argc, char** argv[]){
    int numLinhas, numColunas, i, j, matriz[TAMANHO_MAX_LINHAS][TAMANHO_MAX_COLUNAS], matrizOposta[TAMANHO_MAX_LINHAS][TAMANHO_MAX_COLUNAS];

    scanf("%d",&numLinhas);
    scanf("%d",&numColunas);

    printf("\a");
    //lê a matriz 
    for(i=0;i<numLinhas;i++){
       for(j=0;j<numColunas;j++){
        scanf("%d", &matriz[i][j]);
       }
    }

    for(i=0;i<numLinhas;i++){
       for(j=0;j<numColunas;j++){
        matrizOposta[i][j]= -matriz[i][j];
       }
    }

    for(i=0;i<numLinhas;i++){
       for(j=0;j<numColunas;j++){
        printf("%d", matrizOposta[i][j]);
       }
       printf("\n");
    }

    return SUCESSO;
}