#include <stdio.h>
#include <stdlib.h>
#define SUCESSO 0
void imprime(int vetor[], int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
}
void multiplica(int vetor[], int n, double v){
    int i;
    for(i=0;i<n;i++){
        vetor[i]*=v;
    }
}
int main(int argc, char*argv[]){
    int tamanhoVetor, *vetor, i;
    double valorMultiplicacao;
    scanf("%d", &tamanhoVetor);
    vetor=(int*)malloc(tamanhoVetor*sizeof(int));
    for(i=0;i<tamanhoVetor;i++){
        scanf("%d", &vetor[i]);
    }
    scanf("%lf", &valorMultiplicacao);
    imprime(vetor, tamanhoVetor);
    multiplica(vetor, tamanhoVetor, valorMultiplicacao);
    imprime(vetor, tamanhoVetor);
    multiplica(vetor, tamanhoVetor, (1/valorMultiplicacao));
    imprime(vetor, tamanhoVetor);
    free(vetor);
    return SUCESSO;
}