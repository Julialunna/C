#include <stdio.h>
#define SUCESSO 0
#define TAMANHO_MAX_LINHAS 10
#define TAMANHO_MAX_COLUNAS  10

int main(int agc, char** argv[]){
    int numLinhas, numColunas, i, j, matriz[TAMANHO_MAX_LINHAS][TAMANHO_MAX_COLUNAS], maior;

    scanf("%d",&numLinhas);
    scanf("%d",&numColunas);

    //lê a matriz 
    for(i=0;i<numLinhas;i++){
       for(j=0;j<numColunas;j++){
        scanf("%d", &matriz[i][j]);
       }
    }

     for(i=0;i<numLinhas;i++){
       for(j=0;j<numLinhas;j++){
        printf("%d ", matriz[i][j]);
       }
       printf("\n");
    }
    //define o maior como o primeiro elemento da matriz
    maior= matriz[0][0];
    for(i=0;i<numLinhas;i++){
        for(j=0;j<numColunas;j++){
            ///caso algum valor da matriz seja maior, maior é atualizado
            if(matriz[i][j]>maior){
                maior = matriz[i][j];
            }
        }
    }

    printf("%d", maior);

    return SUCESSO;
}