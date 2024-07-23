#include <stdio.h>
#include <stdlib.h>
#define SUCESSO 0

void calculaSoma(int* vetor1, int* vetor2, int* resultado, int tamanhoVetores){
    int i;
    for(i=0;i<tamanhoVetores;i++){
        resultado[i]=vetor1[i]+vetor2[i];
    }
}

int main(int argc, char*argv[]){
    int *vetorEntrada1, *vetorEntrada2, *vetorResultado;
    int tamanhoVetores, i;

    scanf("%d", &tamanhoVetores);
    vetorEntrada1=(int*)malloc(tamanhoVetores*sizeof(int));
    vetorEntrada2=(int*)malloc(tamanhoVetores*sizeof(int));
    vetorResultado=(int*)malloc(tamanhoVetores*sizeof(int));
    for(i=0;i<tamanhoVetores;i++){
        scanf("%d", &vetorEntrada1[i]);
    }
    for(i=0;i<tamanhoVetores;i++){
        scanf("%d", &vetorEntrada2[i]);
    }
    calculaSoma(vetorEntrada1, vetorEntrada2, vetorResultado, tamanhoVetores);
    for(i=0;i<tamanhoVetores;i++){
        printf("%d\n", vetorResultado[i]);
    }
    free(vetorEntrada1);
    free(vetorEntrada2);
    free(vetorResultado);
    return SUCESSO;
}