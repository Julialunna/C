#include <stdio.h>
#include <stdlib.h>
#define SUCESSO 0
int main(int argc, char*argv[]){
    int tamanhoVetor, i;
    int* vetor;

    scanf("%d", &tamanhoVetor);
    vetor=(int*)malloc(tamanhoVetor*sizeof(int));

    for(i=0;i<tamanhoVetor;i++){
        scanf("%d", &vetor[i]);
    }

    for(i=0;i<tamanhoVetor;i++){
        printf("%d\n", vetor[i]);
    }
    free(vetor);
    return SUCESSO;
}
